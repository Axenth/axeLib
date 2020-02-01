/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 14:44:57 by jlensing       #+#    #+#                */
/*   Updated: 2020/02/01 14:20:36 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = count * size;
	ptr = malloc(i);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, i);
	return ((void *)ptr);
}
