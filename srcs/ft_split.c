/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 17:19:49 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/05 18:03:35 by jlensing      ########   odam.nl         */
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
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !is_char(str[i], s))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !is_char(str[i], s))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_split(char *str, char s)
{
	char	**arr;
	int		i;

	if (str == NULL)
		return (NULL);
	if ((arr = (char **)malloc(sizeof(char *)
										* (count_splits(str, s) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && is_char(*str, s))
			str++;
		if (*str && !is_char(*str, s))
		{
			arr[i] = alloc(str, s);
			i++;
			while (*str && !is_char(*str, s))
				str++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
