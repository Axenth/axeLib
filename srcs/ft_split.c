/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 17:19:49 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/08 13:58:37 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		is_char(char c, char s)
{
	return (c == s);
}

static int		splits(char *str, char s)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		while (*str && is_char(*str, s))
			str++;
		if (*str && !is_char(*str, s))
		{
			counter++;
			while (*str && !is_char(*str, s))
				str++;
		}
	}
	return (counter);
}

static char		*alloc(char *str, char s)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !is_char(str[i], s))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] && !is_char(str[i], s))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char		**loop(char const *s, char c, char **arr, int i)
{
	while (*s)
	{
		while (*s && is_char(*s, c))
			s++;
		if (*s && !is_char(*s, c))
		{
			arr[i] = alloc((char *)s, c);
			if (arr == NULL)
			{
				while (i >= 0)
				{
					free(arr[i]);
					i--;
				}
				return (NULL);
			}
			i++;
			while (*s && !is_char(*s, c))
				s++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

char			**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	if (s == NULL)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * splits((char *)s, c) + 1);
	if (arr == NULL)
		return (NULL);
	i = 0;
	arr = loop(s, c, arr, 0);
	if (arr == NULL)
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}
