/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 14:44:57 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/06 13:55:59 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	ptr = malloc(size * count);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_bzero(ptr, size * count);
	return (ptr);
}
