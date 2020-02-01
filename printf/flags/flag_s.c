/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_s.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 20:00:11 by jlensing       #+#    #+#                */
/*   Updated: 2020/01/14 14:35:27 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/utils.h"
#include "../hdrs/ft_printf.h"

char	*flag_s(char *str, struct s_info info)
{
	char *result;

	if (info.print == e_true)
		result = ft_strdup(str);
	else
		result = ft_strdup("");
	return (result);
}
