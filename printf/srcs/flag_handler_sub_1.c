/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_handler_sub_1.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 19:53:53 by jlensing      #+#    #+#                 */
/*   Updated: 2020/10/23 19:30:41 by axenth        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/utils.h"
#include <stdlib.h>

struct s_info	print_str(struct s_info info, char *str)
{
	if (info.print == e_true)
		info = ft_putstr_fd(info.fd, str, info.toprint, info);
	return (info);
}

struct s_info	set_info_values(char *str, void *temp, struct s_info info)
{
	if (info.precision_flag == e_false && temp != NULL)
		info.toprint = ft_strlen(str);
	if (info.format_type == 1 && temp == NULL)
		info.amount += 1;
	if (info.format_type == 8 || info.format_type == 3)
	{
		info.precision_flag = e_false;
		info.print = e_true;
		info.toprint = ft_strlen(str);
	}
	if (info.format_type >= 4 && info.format_type <= 7 &&
						info.toprint < ft_strlen(str) && temp != NULL)
	{
		info.toprint = ft_strlen(str);
		info.print = e_true;
	}
	if (info.dash_flag == e_true)
		info.zero_flag = e_false;
	if (info.precision_flag == e_true && info.format_type >= 4 &&
														info.format_type <= 7)
		info.zero_flag = e_false;
	if (temp == NULL && info.precision_flag == e_false &&
						(info.format_type >= 4 && info.format_type <= 7))
		info.toprint = 1;
	return (info);
}

struct s_info	set_second_info_values(struct s_info info, char *str,
																void *temp)
{
	if (info.precision_flag == e_true && info.format_type == 2 &&
										(ft_strlen(str) < info.toprint))
		info.toprint = ft_strlen(str);
	if (info.width_flag == e_true && info.format_type == 3)
	{
		if (ft_strlen(str) != 1)
			info.width -= 2;
	}
	if (info.width_flag == e_true && info.format_type == 4)
	{
		if (info.negative_flag == e_true)
			info.width -= 1;
	}
	if (info.format_type == 4 && info.toprint < ft_strlen(str))
		info.toprint = ft_strlen(str);
	if (info.print == e_true && info.toprint < ft_strlen(str) &&
		(info.format_type >= 4 && info.format_type <= 7))
		info.toprint = ft_strlen(str);
	if (info.format_type == 4 && temp == NULL && info.precision_flag == e_true
															&& info.prec == 0)
		info.print = e_false;
	if (info.format_type == 4 && temp == NULL && info.precision_flag == e_true
															&& info.prec != 0)
		info.print = e_true;
	return (info);
}

struct s_info	handle_extras(struct s_info info, void *temp)
{
	if (info.format_type == 4 && temp == NULL && info.print == e_false &&
													info.width == 0)
		info.amount -= 1;
	if (info.format_type == 1 && temp == NULL && info.print == e_true)
		info = ft_putchar_fd(info.fd, '\0', info);
	if (info.format_type == 3)
	{
		info = ft_putstr_fd(info.fd, "0x", 3, info);
		info.amount += 2;
	}
	return (info);
}

void			handle_zeros(struct s_info info, char *str)
{
	int i;

	i = 0;
	if (info.precision_flag == e_true &&
							(info.format_type >= 4 && info.format_type <= 7))
	{
		while (i < info.toprint - ft_strlen(str))
		{
			info = ft_putchar_fd(info.fd, '0', info);
			i++;
		}
		i = 0;
	}
}
