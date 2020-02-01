/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 15:40:18 by jlensing       #+#    #+#                */
/*   Updated: 2020/01/14 14:35:27 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/utils.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		size;
	int		counter;
	char	*dup;

	size = 0;
	counter = 0;
	size = ft_strlen(s1);
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
