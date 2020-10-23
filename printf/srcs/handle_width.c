/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_width.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 18:26:00 by jlensing      #+#    #+#                 */
/*   Updated: 2020/10/23 19:30:13 by axenth        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/utils.h"

int		handle_width(struct s_info info, char *str, int i)
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
	{
		while (i < ((info.width - ft_strlen(str)) +
								(ft_strlen(str) - info.toprint)))
		{
			info = ft_putchar_fd(info.fd, ' ', info);
			i++;
		}
		while (info.width == info.toprint &&
							i < info.width - ft_strlen(str))
		{
			info = ft_putchar_fd(info.fd, ' ', info);
			i++;
		}
	}
	return (i);
}
