/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 16:48:44 by jlensing       #+#    #+#                */
/*   Updated: 2020/02/01 14:20:36 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"
#include <stdlib.h>

static size_t	in_set(char s, char const *set)
{
	size_t i;

	i = 0;
	while (i < ft_strlen((char *)set))
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	in_range(char const *s1, char const *set, int end)
{
	size_t i;

	i = 0;
	while (s1[i] != '\0' && end == 0)
	{
		if (!in_set(s1[i], set))
			return (i);
		i++;
	}
	if (end)
	{
		i = ft_strlen((char *)s1) - 1;
		while (i > 0)
		{
			if (!in_set(s1[i], set))
				return (i);
			i--;
		}
	}
	return (0);
}

static char		*cpy_string(char const *s1, size_t start, size_t end)
{
	char	*trimmedstr;
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	trimmedstr = malloc((end - start) + 2 * sizeof(char));
	if (trimmedstr == NULL)
		return (NULL);
	while (i2 < ft_strlen((char *)s1))
	{
		if (i2 >= start && i2 <= end)
		{
			trimmedstr[i] = s1[i2];
			i++;
		}
		i2++;
	}
	trimmedstr[i] = '\0';
	return (trimmedstr);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmedstr;
	size_t	start;
	size_t	end;

	if (s1 == NULL)
		return (NULL);
	start = in_range(s1, set, 0);
	end = in_range(s1, set, 1);
	if (start == end)
		return (ft_strdup(""));
	trimmedstr = cpy_string(s1, start, end);
	if (trimmedstr == NULL)
		return (NULL);
	return (trimmedstr);
}
