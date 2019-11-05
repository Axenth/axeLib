/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 13:09:19 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/05 18:46:03 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char		*src;
	unsigned long	n;

	n = 0;
	src = s;
	while (s[n] >= 001 && s[n] <= 0177)
		n++;
	while (n > 0)
	{
		if (src[n] == '\0' && c != '\0')
			n--;
		if (src[n] == c)
			return ((char *)s + n);
		n--;
	}
	if (src[n] == c)
		return ((char *)s);
	return (NULL);
}
