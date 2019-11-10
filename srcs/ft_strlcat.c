/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 18:29:28 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/08 14:12:55 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*tdst;
	char		*tsrc;
	size_t		n;
	size_t		n2;

	tdst = (char *)ft_memchr(dst, '\0', dstsize);
	if (!tdst)
		return (dstsize + ft_strlen((char *)src));
	tdst = (char *)dst;
	tsrc = (char *)src;
	n = ft_strlen(tdst);
	n2 = n + ft_strlen(tsrc);
	tdst += n;
	while (n < dstsize - 1 && *tsrc)
	{
		*tdst = *tsrc;
		tdst++;
		tsrc++;
		n++;
	}
	*tdst = '\0';
	return (n2);
}
