/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:49:58 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/13 14:10:55 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	i2;

	i = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		i2 = 0;
		while (haystack[i + i2] == needle[i2] &&
				i + i2 < len)
		{
			i2++;
			if (!needle[i2])
				return ((char*)haystack + i);
		}
		i++;
	}
	return (NULL);
}
