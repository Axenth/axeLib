/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_handler_sub_2.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 20:33:19 by jlensing      #+#    #+#                 */
/*   Updated: 2020/10/23 19:30:13 by axenth        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/utils.h"
#include <stdlib.h>

static void	print_width(struct s_info info, char *str, int type, int i)
{
	while (i < ((info.width - ft_strlen(str)) +
				(ft_strlen(str) - info.toprint)) && type == 0)
	{
		info = ft_putchar_fd(info.fd, ' ', info);
		i++;
	}
	while (i < ((info.width - ft_strlen(str)) +
				(ft_strlen(str) - info.toprint)) && type == 1)
	{
		info = ft_putchar_fd(info.fd, '0', info);
		i++;
	}
	while (i < (info.width - info.toprint) && type == 2)
	{
		info = ft_putchar_fd(info.fd, ' ', info);
		i++;
	}
	while (info.width == info.toprint &&
				i < info.width - ft_strlen(str) && type == 3)
	{
		info = ft_putchar_fd(info.fd, ' ', info);
		i++;
	}
}

void		width_true(struct s_info info, char *str, int i)
{
	if (info.width_flag == e_true)
	{
		if (info.dash_flag == e_false && info.zero_flag == e_false)
		{
			if (info.print == e_true)
			{
				if (ft_strlen(str) - info.toprint < 0)
					print_width(info, str, 2, i);
				else
				{
					print_width(info, str, 0, i);
					print_width(info, str, 3, i);
				}
			}
			else
			{
				while (i < info.width)
				{
					info = ft_putchar_fd(info.fd, ' ', info);
					i++;
				}
			}
		}
	}
}

void		width_zero_true(struct s_info info, char *str, int i)
{
	if (info.width_flag == e_true && info.dash_flag == e_false
								&& info.zero_flag == e_true)
	{
		if (check_zero_flag(info) == e_true)
		{
			if (info.print == e_true)
			{
				print_width(info, str, 1, i);
			}
			else
			{
				while (i < info.width)
				{
					info = ft_putchar_fd(info.fd, '0', info);
					i++;
				}
			}
		}
	}
}

void		width_dash_true(struct s_info info, char *str, int i)
{
	if (info.width_flag == e_true && info.dash_flag == e_true)
	{
		if (info.print == e_true)
		{
			if (ft_strlen(str) - info.toprint < 0)
			{
				while (i < (info.width - info.toprint))
				{
					info = ft_putchar_fd(info.fd, ' ', info);
					i++;
				}
			}
			else
				print_width(info, str, 0, i);
		}
		else
		{
			while (i < info.width)
			{
				info = ft_putchar_fd(info.fd, ' ', info);
				i++;
			}
		}
	}
}
