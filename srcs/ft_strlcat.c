/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 18:29:28 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/02 13:19:36 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*tdst;
	char		*tsrc;
	size_t		n;
	size_t		n2;

	if (!(tdst = (char *)ft_memchr(dst, '\0', dstsize)))
		return (dstsize + ft_strlen((char *)src));
	tdst = (char *)dst;
	tsrc = (char *)src;
	n = ft_strlen(tdst);
	n2 = n + ft_strlen(tsrc);
	tdst += n;
	while (n < dstsize - 1 && *tsrc)
	{
		*tdst++ = *tsrc++;
		n++;
	}
	*tdst = '\0';
	return (n2);
}
