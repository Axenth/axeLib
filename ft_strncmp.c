/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:29:47 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/01 18:22:54 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned long i;

	i = 0;
	while (i < n && str1[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] - 48 > str2[i] - 48)
				return (1);
			else if (str1[i] - 48 < str2[i] - 48)
				return (-1);
		}
		i++;
	}
	return (0);
}
