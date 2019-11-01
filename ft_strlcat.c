/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 18:29:28 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/01 12:51:50 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*tdst;
	char		*tend;
	const char	*tsrc;

	tdst = dst;
	tend = dst + dstsize;
	tsrc = src;
	while (*tdst)
		tdst++;
	while (*tsrc != '\0' && tdst < tend)
		*tdst++ = *tsrc++;
	if (tdst < tend)
		*tdst = 0;
	else if (dstsize > 0)
		tdst[0] = 0;
	while (*tdst != '\0')
		tdst++;
	return ((tdst - dst) + (tsrc - src));
}
