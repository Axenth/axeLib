/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_u.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:46:15 by jlensing       #+#    #+#                */
/*   Updated: 2020/01/14 14:35:27 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/utils.h"

char	*flag_u(unsigned int value)
{
	char *str;

	str = ft_itoa_unsigned(value);
	return (str);
}
