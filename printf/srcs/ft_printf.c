/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 16:08:18 by jlensing      #+#    #+#                 */
/*   Updated: 2020/10/23 19:31:42 by axenth        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/utils.h"
#include <stdarg.h>

static struct s_info		reset_struct(struct s_info info)
{
	info.width = 0;
	info.width_flag = e_false;
	info.dash_flag = e_false;
	info.zero_flag = e_false;
	info.precision_flag = e_false;
	info.toprint = 0;
	info.prec = 0;
	info.print = e_true;
	info.negative_flag = e_false;
	info.skip = e_false;
	info.error = e_false;
	return (info);
}

static struct s_info		init_struct(int fd)
{
	struct s_info info;

	info.format_type = 0;
	info.position = 0;
	info.width = 0;
	info.toprint = 0;
	info.amount = 0;
	info.prec = 0;
	info.fd = fd;
	info.width_flag = e_false;
	info.dash_flag = e_false;
	info.zero_flag = e_false;
	info.precision_flag = e_false;
	info.print = e_true;
	info.negative_flag = e_false;
	info.skip = e_false;
	info.error = e_false;
	return (info);
}

static struct s_info		ft_printf_loop(const char *format, int i,
										va_list args, struct s_info info)
{
	int temp;

	info.format_type = 0;
	if (format[i] == '%')
	{
		info = flag_checker(format, i, info, args);
		if (info.format_type && info.skip == e_false)
		{
			temp = info.position;
			info = flag_handler(info, args);
			if (info.error == e_true)
				return (info);
			if (info.width > info.toprint)
				info.amount += info.width;
			else if (info.width <= info.toprint)
				info.amount += info.toprint;
			i = temp;
		}
		info = reset_struct(info);
	}
	return (info);
}

int							ft_printf(const char *format, ...)
{
	int					i;
	va_list				args;
	struct s_info		info;

	info = init_struct(1);
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			info = ft_printf_loop(format, i, args, info);
			i = info.position;
		}
		else if (format[i] != '%')
		{
			info = ft_putchar_fd(info.fd, format[i], info);
			info.amount++;
		}
		if (info.error == e_true)
			return (-1);
		i++;
	}
	va_end(args);
	return (info.amount);
}

int							ft_fprintf(int fd, const char *format, ...)
{
	int					i;
	va_list				args;
	struct s_info		info;

	info = init_struct(fd);
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			info = ft_printf_loop(format, i, args, info);
			i = info.position;
		}
		else if (format[i] != '%')
		{
			info = ft_putchar_fd(info.fd, format[i], info);
			info.amount++;
		}
		if (info.error == e_true)
			return (-1);
		i++;
	}
	va_end(args);
	return (info.amount);
}
