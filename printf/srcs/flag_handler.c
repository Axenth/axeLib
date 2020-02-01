/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_handler.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 16:39:52 by jlensing       #+#    #+#                */
/*   Updated: 2020/01/14 14:35:27 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/utils.h"
#include <stdarg.h>
#include <stdlib.h>

t_bool					check_zero_flag(struct s_info info)
{
	if (info.format_type >= 1 || info.format_type <= 3 || info.format_type == 8)
		return (e_true);
	if ((info.format_type >= 4 && info.format_type <= 7) &&
												info.precision_flag == e_false)
		return (e_true);
	return (e_false);
}

static struct s_info	handle_functions(struct s_info info, char *str,
											void *temp)
{
	if (info.format_type == 3 && temp == NULL)
		info.width -= 2;
	if (info.format_type == 2 && temp == NULL && info.precision_flag == e_false)
		info.width += 1;
	info = set_second_info_values(info, str, temp);
	width_true(info, str, 0);
	if (info.negative_flag == e_true)
	{
		info = ft_putchar_fd(1, '-', info);
		info.amount += 1;
	}
	width_zero_true(info, str, 0);
	info = handle_extras(info, temp);
	handle_zeros(info, str);
	info = print_str(info, str);
	width_dash_true(info, str, 0);
	return (info);
}

struct s_handler_info	null_check(char *str, struct s_info info, void *temp)
{
	struct s_handler_info handler_info;

	if (temp == NULL && (info.format_type < 4 || info.format_type > 7))
	{
		handler_info = handle_nulls(info, str);
		info = handler_info.info;
		str = handler_info.str;
		if (info.format_type != 3 && info.format_type != 1)
		{
			handler_info = handle_second_nulls(info, str);
			info = handler_info.info;
			str = handler_info.str;
		}
	}
	handler_info.info = info;
	handler_info.str = str;
	return (handler_info);
}

struct s_info			flag_handler(struct s_info info, va_list args)
{
	void					*temp;
	char					*str;
	struct s_handler_info	handler_info;

	info = handle_initial_info(info);
	temp = set_temp(info, args);
	str = get_str(info, temp);
	if (str == NULL)
	{
		info.error = e_true;
		return (info);
	}
	if (info.format_type == 4 && (signed int)temp < 0)
		info.negative_flag = e_true;
	info = set_info_values(str, temp, info);
	handler_info = null_check(str, info, temp);
	info = handler_info.info;
	str = handler_info.str;
	info = handle_functions(info, str, temp);
	free(str);
	return (info);
}
