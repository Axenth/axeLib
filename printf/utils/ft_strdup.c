/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 15:40:18 by jlensing       #+#    #+#                */
/*   Updated: 2020/03/25 21:55:15 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/utils.h"
#include <stdlib.h>

char	*ft_strdup_util(const char *s1)
{
	int		size;
	int		counter;
	char	*dup;

	size = 0;
	counter = 0;
	size = ft_strlen_util(s1);
	dup = malloc(sizeof(char) * size + 1);
	if (dup == NULL)
		return (NULL);
	while (counter < size)
	{
		dup[counter] = s1[counter];
		counter++;
	}
	dup[counter] = '\0';
	return (dup);
}
