/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 17:19:49 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/05 18:08:30 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		is_char(char c, char s)
{
	return (c == s);
}

static int		count_splits(char *str, char s)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_char(*str, s))
			str++;
		if (*str && !is_char(*str, s))
		{
			count++;
			while (*str && !is_char(*str, s))
				str++;
		}
	}
	return (count);
}

static char		*alloc(char *str, char s)
{
	char	*part;
	int		i;

	i = 0;
	while (str[i] && !is_char(str[i], s))
		i++;
	part = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !is_char(str[i], s))
	{
		part[i] = str[i];
		i++;
	}
	part[i] = '\0';
	return (part);
}

char			**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	if (s == NULL)
		return (NULL);
	if ((arr = (char **)malloc(sizeof(char *)
								* (count_splits((char *)s, c) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && is_char(*s, c))
			s++;
		if (*s && !is_char(*s, c))
		{
			arr[i] = alloc((char *)s, c);
			i++;
			while (*s && !is_char(*s, c))
				s++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
