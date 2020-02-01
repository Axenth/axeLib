/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_handler_sub_3.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 15:39:19 by jlensing       #+#    #+#                */
/*   Updated: 2020/01/14 14:35:27 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/utils.h"
#include <stdarg.h>
#include <stdlib.h>

struct s_info			handle_initial_info(struct s_info info)
{
	if (info.width < 0)
	{
		info.width *= -1;
		info.dash_flag = e_true;
	}
	if (info.toprint < 0)
		info.precision_flag = e_false;
	return (info);
}

void					*set_temp(struct s_info info, va_list args)
{
	void *temp;

	if (info.format_type != 8)
		temp = NULL;
	if (info.format_type != 8 && info.format_type != 0)
		temp = va_arg(args, void *);
	else if (info.format_type != 8)
		temp = NULL;
	return (temp);
}

char					*get_str(struct s_info info, void *temp)
{
	char *str;

	if (info.format_type == 1 && temp != NULL)
		str = flag_c((char)temp);
	else if (info.format_type == 2 && temp != NULL)
		str = flag_s((char *)temp, info);
	else if (info.format_type == 3)
		str = flag_p((unsigned long)temp, info);
	else if (info.format_type == 4)
		str = flag_di((signed int)temp);
	else if (info.format_type == 5)
		str = flag_u((unsigned int)temp);
	else if (info.format_type == 6)
		str = flag_x((unsigned int)temp, e_false);
	else if (info.format_type == 7)
		str = flag_x((unsigned int)temp, e_true);
	else if (info.format_type == 8 && temp != NULL)
		str = flag_procent();
	else
		str = ft_strdup("");
	return (str);
}

struct s_handler_info	handle_nulls(struct s_info info, char *str)
{
	struct s_handler_info hi;

	if (info.toprint == 0 && info.format_type != 99)
	{
		if (info.format_type == 3)
			info.toprint = 3;
		else if (info.format_type == 1 || info.format_type == 2)
		{
			if (info.print == e_true)
				info.width -= 1;
		}
		else
			info.toprint = 6;
	}
	hi.info = info;
	hi.str = str;
	return (hi);
}

struct s_handler_info	handle_second_nulls(struct s_info info, char *str)
{
	struct s_handler_info hi;

	if (ft_strncmp(str, "", 1) == 0)
		free(str);
	str = ft_strdup("(null)");
	if (info.precision_flag == e_false)
		info.toprint = ft_strlen(str);
	hi.info = info;
	hi.str = str;
	return (hi);
}
