/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_p.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 20:37:16 by jlensing      #+#    #+#                 */
/*   Updated: 2020/01/14 14:35:27 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/utils.h"
#include <stdlib.h>

static char	*fill_zero(int n)
{
	int		i;
	char	*hex;

	i = 0;
	hex = malloc(sizeof(char) * n + 1);
	if (hex == NULL)
		return (NULL);
	while (i < n)
	{
		hex[i] = '0';
		i++;
	}
	hex[i] = '\0';
	return (hex);
}

char		*flag_p(unsigned long ptr, struct s_info info)
{
	char	*hex;
	int		i;

	i = 15;
	hex = convert_to_hex(ptr);
	if ((ptr == 0) && info.precision_flag == e_true)
	{
		free(hex);
		hex = fill_zero(info.toprint);
	}
	else if (ptr == 0)
	{
		free(hex);
		hex = malloc(sizeof(char) * 2);
		if (hex == NULL)
			return (NULL);
		hex[0] = '0';
		hex[1] = '\0';
	}
	while (i >= 0)
	{
		hex[i] = ft_tolower(hex[i]);
		i--;
	}
	return (hex);
}
