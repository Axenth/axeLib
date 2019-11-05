/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 15:40:18 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/01 16:02:43 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	counter;
	char	*dup;

	size = 0;
	counter = 0;
	while (s1[size] != '\0')
		size++;
	if ((dup = malloc(size * sizeof(char) + 1)) == NULL)
		return (NULL);
	while (counter < size)
	{
		dup[counter] = s1[counter];
		counter++;
	}
	dup[counter] = '\0';
	return (dup);
}
