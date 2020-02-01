/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_checker.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 16:23:27 by jlensing       #+#    #+#                */
/*   Updated: 2020/01/14 14:35:27 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/utils.h"
#include <stdlib.h>

static struct s_info	check_flags(struct s_info info, const char *string,
									int position, va_list args)
{
	while (string[position] == '-' || string[position] == '0')
	{
		if (string[position] == '-')
		{
			info.dash_flag = e_true;
		}
		if (string[position] == '0')
		{
			info.zero_flag = e_true;
		}
		position++;
	}
	if (string[position] == '*')
	{
		info.width_flag = e_true;
		info.width = va_arg(args, int);
		position++;
	}
	info.position = position;
	return (info);
}

int						check_format(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (2);
	if (c == 'p')
		return (3);
	if (c == 'd' || c == 'i')
		return (4);
	if (c == 'u')
		return (5);
	if (c == 'x')
		return (6);
	if (c == 'X')
		return (7);
	if (c == '%')
		return (8);
	return (0);
}

struct s_info			check_initial_precision(const char *string,
										int position, struct s_info info)
{
	if (string[position] == '.')
	{
		if (in_set(string[position + 1]))
		{
			position += 1;
			info.print = e_false;
		}
		while (!in_set(string[position]) && !in_flag_set(string[position]))
		{
			position++;
		}
	}
	info.position = position;
	return (info);
}

static struct s_info	set_values(struct s_info info,
				struct s_width width_info, const char *string, int position)
{
	width_info = flag_width(string, position, width_info);
	info.width = width_info.width;
	info.position = width_info.pos;
	info.width_flag = e_true;
	return (info);
}

struct s_info			flag_checker(const char *string, int position,
									struct s_info info, va_list args)
{
	struct s_width width_info;

	info.format_type = 0;
	position += 1;
	info.position = position;
	width_info.pos = position;
	info = check_initial_precision(string, position, info);
	info = check_flags(info, string, position, args);
	position = info.position;
	if (string[position] >= '1' && string[position] <= '9')
		info = set_values(info, width_info, string, position);
	info = check_precision(string, info.position, info, args);
	position = info.position;
	info.format_type = check_format(string[position]);
	info.position = position;
	if (info.format_type == 0)
		info.skip = e_true;
	if (info.format_type == 1 && info.precision_flag == e_true)
	{
		info.toprint = 1;
		info.print = e_true;
	}
	return (info);
}
