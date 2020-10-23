/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 14:14:13 by jlensing      #+#    #+#                 */
/*   Updated: 2020/01/14 14:35:27 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/utils.h"

char	*flag_x(unsigned int value, t_bool uppercase)
{
	char	*str;
	int		i;

	if (value == 0)
		str = ft_strdup("0");
	else
		str = convert_to_hex(value);
	i = ft_strlen(str);
	if (uppercase == e_true)
	{
		while (i >= 0)
		{
			str[i] = ft_toupper(str[i]);
			i--;
		}
	}
	else if (uppercase == e_false)
	{
		while (i >= 0)
		{
			str[i] = ft_tolower(str[i]);
			i--;
		}
	}
	return (str);
}
