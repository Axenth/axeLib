/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrmchr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 16:48:44 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/01 16:49:49 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	count_set_chars(char const *s1, char const *set)
{
	size_t i;
	size_t i2;
	size_t counter;

	i = 0;
	i2 = 0;
	counter = 0;
	while (i < ft_strlen((char *)s1))
	{
		while (i2 < ft_strlen((char *)set))
		{
			if (s1[i] == set[i2])
				counter++;
			i2++;
		}
		i2 = 0;
		i++;
	}
	return (counter);
}

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

char	*ft_strrmchr(char const *s1, char const *set)
{
	char	*trimmedstr;
	size_t	i;
	size_t	i2;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	i2 = 0;
	if ((trimmedstr = malloc((ft_strlen((char *)s1) - count_set_chars(s1, set)) + 1 * sizeof(char))) == NULL)
		return (NULL);
	while (i2 < ft_strlen((char *)s1))
	{
		if (!in_set(s1[i2], set))
		{
			trimmedstr[i] = s1[i2];
			i++;
		}
		i2++;
	}
	trimmedstr[i + 1] = '\0';
	return (trimmedstr);
}
