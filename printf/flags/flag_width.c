/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_width.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 15:44:19 by jlensing      #+#    #+#                 */
/*   Updated: 2020/01/14 14:35:27 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/utils.h"
#include <stdlib.h>

struct s_width	flag_width(const char *str, int position, struct s_width info)
{
	int		start;
	int		end;
	int		len;
	char	*result;
	int		i;

	i = 0;
	start = position;
	while (str[position] >= '0' && str[position] <= '9')
		position++;
	end = position - 1;
	len = end - start;
	result = malloc(sizeof(char) * (len + 1));
	while (i <= len)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	info.width = ft_atoi(result);
	info.pos = end + 1;
	free(result);
	return (info);
}
