/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 16:11:24 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/02 16:35:22 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"
#include <stdlib.h>

static char		*calc_result_strjoin(int sizestr1, int sizestr2,
									char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	if ((result = malloc((sizestr1 + sizestr2) * sizeof(char))) == NULL)
		return (NULL);
	while ((i < sizestr1 && flag == 0) || (i < sizestr2 && flag == 1))
	{
		if (i < sizestr1 && flag == 0)
		{
			result[i] = s1[i];
			if (i == sizestr1 - 1)
			{
				flag = 1;
				i = 0;
			}
		}
		if (i < sizestr2 && flag == 1)
			result[sizestr1 + i] = s2[i];
		i++;
	}
	return (result);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		sizestr1;
	int		sizestr2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	sizestr1 = ft_strlen((char *)s1);
	sizestr2 = ft_strlen((char *)s2);
	result = calc_result_strjoin(sizestr1, sizestr2, s1, s2);
	return (result);
}
