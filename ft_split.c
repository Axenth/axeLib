/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 17:19:49 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/02 20:46:05 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"
#include <stdlib.h>

static int	count_splits(char const *s, char c)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			counter++;
		i++;
	}
	return (counter);
}

static int		find_next_start(char const *s, char c, int count)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i] + 1 != c)
			counter++;
		if (counter == count)
			return (i);
		i++;
	}
	return (0);
}

static char		*put_into_array(char const *s, int start, int end, int size)
{
	char	*result;
	int		i;

	if ((result = malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		result[i] = s[start];
		start++;
		i++;
	}
	return (result);
}

static int	getsize(char const *s, char c, int count)
{
	int counter;
	int i;
	int flag;
	int i2;

	counter = 0;
	i = 0;
	flag = 0;
	i2 = 0;
	while (s[i] != '\0')
	{
		if (s[i + 1] == c && flag == 1)
		{
			return (counter - 1);
		}
		if (s[i] == c && i2 != count)
			i2++;
		if (s[i] == c && i2 == count - 1)
			flag = 1;
		if (flag == 1)
			counter++;
		i++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		splits;

	splits = count_splits(s, c);
	if ((result = malloc(splits * sizeof(char*))) == NULL)
		return (NULL);
	i = 0;
	while (i < splits)
	{
		result[i] = put_into_array(s, find_next_start(s, c, i),
							find_next_start(s, c, i + 1), getsize(s, c, i));
		i++;
	}
	return (result);
}
