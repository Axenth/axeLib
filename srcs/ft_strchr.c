/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:56:03 by jlensing      #+#    #+#                 */
/*   Updated: 2020/04/06 19:10:26 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	const char		*src;
	unsigned long	i;
	unsigned long	n;

	i = 0;
	n = 0;
	src = s;
	while (s[n] != '\0')
		n++;
	n++;
	while (i < n)
	{
		if (src[i] == '\0' && c != '\0')
			return (NULL);
		if (src[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
