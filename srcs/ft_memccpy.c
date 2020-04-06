/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 17:39:00 by jlensing      #+#    #+#                 */
/*   Updated: 2020/04/06 19:10:26 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tdst;
	unsigned char	*tsrc;
	size_t			i;

	tdst = (unsigned char *)dst;
	tsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		tdst[i] = tsrc[i];
		if (tdst[i] == (unsigned char)c)
		{
			return ((void *)tdst + i + 1);
		}
		i++;
	}
	return (NULL);
}
