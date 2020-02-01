/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_di.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 21:18:57 by jlensing       #+#    #+#                */
/*   Updated: 2020/01/14 14:35:27 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/utils.h"

char	*flag_di(signed int value)
{
	char *str;

	if (value < 0)
		value *= -1;
	str = ft_itoa(value);
	return (str);
}
