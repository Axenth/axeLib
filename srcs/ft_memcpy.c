/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 17:17:21 by jlensing      #+#    #+#                 */
/*   Updated: 2020/04/06 19:10:26 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tdst;
	unsigned char	*tsrc;
	size_t			i;

	tdst = (unsigned char *)dst;
	tsrc = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL && n > 0)
		return (NULL);
	while (i < n)
	{
		tdst[i] = tsrc[i];
		i++;
	}
	return (tdst);
}
