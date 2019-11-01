/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 14:44:57 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/01 18:09:04 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/errno.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*s;

	i = count * size;
	s = malloc(i);
	if (s == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	return (s);
}
