/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:49:58 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/10 17:15:42 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (needle[0] == '\0' || len == 0 || needle == haystack)
		return ((char *)haystack);
	while (needle[i[2]] != '\0' && i[2] < len)
		i[2]++;
	while (haystack[i[0]] != '\0' && i[0] < len)
	{
		if (haystack[i[0]] == needle[i[1]])
		{
			while (haystack[i[0] + i[1]] == needle[i[1]] && i[2] < len)
			{
				if (i[1] == i[2] - 1)
					return ((char *)haystack + i[0]);
				i[1]++;
			}
			i[1] = 0;
		}
		i[0]++;
	}
	return (NULL);
}
