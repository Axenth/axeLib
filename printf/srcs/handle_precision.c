/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_precision.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 17:25:02 by jlensing       #+#    #+#                */
/*   Updated: 2020/03/25 21:55:50 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/utils.h"
#include <stdlib.h>

static struct s_info		set_values(int position, int prec_value
												, struct s_info info)
{
	info.position += position;
	info.precision_flag = e_true;
	info.toprint = prec_value;
	info.prec = prec_value;
	info.position = position;
	return (info);
}

static struct s_info		unpack_prec_data(struct s_info info,
										struct s_prec_data prec_data)
{
	info.format_type = prec_data.info.format_type;
	info.print = prec_data.info.print;
	info.position = prec_data.info.position;
	info.precision_flag = prec_data.info.precision_flag;
	info.toprint = prec_data.info.toprint;
	info.prec = prec_data.info.prec;
	return (info);
}

static struct s_info		if_posistion_astrix(struct s_info info,
														va_list args)
{
	info.precision_flag = e_true;
	info.toprint = va_arg(args, int);
	info.prec = info.toprint;
	info.position += 2;
	return (info);
}

static struct s_prec_data	while_string_is_dot(struct s_prec_data prec_data)
{
	prec_data.start = 0;
	if (in_set(prec_data.string[prec_data.position]) == e_false)
		prec_data.start = prec_data.position;
	while (!in_set(prec_data.string[prec_data.position]))
		prec_data.position++;
	prec_data.s = ft_substr_util(prec_data.string, prec_data.start,
										prec_data.position - prec_data.start);
	if (prec_data.s != NULL)
	{
		prec_data.prec_value = ft_atoi_util(prec_data.s);
		free(prec_data.s);
	}
	if (prec_data.prec_value == 0)
	{
		prec_data.info.format_type = 99;
		prec_data.info.print = e_false;
	}
	prec_data.info = set_values(prec_data.position,
									prec_data.prec_value, prec_data.info);
	return (prec_data);
}

struct s_info				check_precision(const char *string, int position,
										struct s_info info, va_list args)
{
	struct s_prec_data data;

	data.info = info;
	data.string = string;
	while (string[position] == '.')
	{
		position++;
		if (string[position] == '*')
		{
			info = if_posistion_astrix(info, args);
			break ;
		}
		data.position = position;
		data = while_string_is_dot(data);
		info = unpack_prec_data(info, data);
	}
	return (info);
}
