/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 14:14:13 by jlensing       #+#    #+#                */
/*   Updated: 2020/03/25 21:56:30 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/utils.h"

char	*flag_x(unsigned int value, t_bool uppercase)
{
	char	*str;
	int		i;

	if (value == 0)
		str = ft_strdup_util("0");
	else
		str = convert_to_hex_util(value);
	i = ft_strlen_util(str);
	if (uppercase == e_true)
	{
		while (i >= 0)
		{
			str[i] = ft_toupper_util(str[i]);
			i--;
		}
	}
	else if (uppercase == e_false)
	{
		while (i >= 0)
		{
			str[i] = ft_tolower_util(str[i]);
			i--;
		}
	}
	return (str);
}
