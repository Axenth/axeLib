/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 18:29:28 by jlensing       #+#    #+#                */
/*   Updated: 2020/03/25 21:55:15 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/utils.h"

size_t		ft_strlcat_util(char *dst, const char *src, size_t dstsize)
{
	size_t dstl;
	size_t srcl;

	dstl = ft_strlen_util(dst);
	srcl = ft_strlen_util(src);
	if (!dstsize || dstsize < dstl)
		return (dstl + srcl - (dstl - dstsize));
	dstsize -= dstl;
	ft_strlcpy_util(dst + dstl, src, dstsize);
	return (dstl + srcl);
}
