/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_di.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 21:18:57 by jlensing      #+#    #+#                 */
/*   Updated: 2020/04/06 19:10:26 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/utils.h"

char	*flag_di(signed int value)
{
	char *str;

	if (value < 0)
		value *= -1;
	str = ft_itoa_util(value);
	return (str);
}
