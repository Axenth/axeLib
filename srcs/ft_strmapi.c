/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 15:44:04 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/06 13:57:32 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;
	int				size;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	size = ft_strlen((char *)s);
	if ((result = malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(result, s, size);
	while (result[i])
	{
		result[i] = (*f)(i, result[i]);
		i++;
	}
	result[size] = '\0';
	return ((char *)result);
}
