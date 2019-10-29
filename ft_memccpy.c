/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 17:39:00 by jlensing       #+#    #+#                */
/*   Updated: 2019/10/29 18:53:28 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*tdst;
	char	*tsrc;
	size_t	i;

	tdst = (char *)dst;
	tsrc = (char *)src;
	i = 0;
	while (i < n)
	{
		tdst[i] = tsrc[i];
		if (tdst[i] == c)
		{
			break ;
		}
		i++;
	}
	return (tdst);
}
