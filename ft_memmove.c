/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 18:56:17 by jlensing       #+#    #+#                */
/*   Updated: 2019/10/29 19:13:10 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tdst;
	char	*tsrc;
	char	tmp[len];
	size_t	i;

	tdst = (char *)dst;
	tsrc = (char *)src;
	i = 0;
	while (i < len)
	{
		tmp[i] = tsrc[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		tdst[i] = tmp[i];
		i++;
	}
	return (tdst);
}
