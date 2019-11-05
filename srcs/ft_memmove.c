/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 18:56:17 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/01 17:47:53 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tdst;
	char	*tsrc;
	size_t	counter;

	tdst = (char *)dst;
	tsrc = (char *)src;
	counter = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		while (counter < len)
		{
			tdst[counter] = tsrc[counter];
			counter++;
		}
	else
	{
		counter = len;
		while (counter != 0)
		{
			tdst[counter - 1] = tsrc[counter - 1];
			counter--;
		}
	}
	return (tdst);
}
