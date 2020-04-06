/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 17:19:49 by jlensing      #+#    #+#                 */
/*   Updated: 2020/04/06 19:10:26 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		calc(const char *s, int c)
{
	int		i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	if (count == 1)
		return (1);
	return (count + 1);
}

static char		*get_next_str(char const **s, char c)
{
	size_t	i;
	size_t	i2;
	char	*str;
	char	*ret;

	str = (char*)*s;
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	i2 = 0;
	ret = malloc(sizeof(char) * i + 1);
	if (!ret)
		return (NULL);
	while (i2 < i)
	{
		ret[i2] = *str;
		str++;
		i2++;
	}
	ret[i2] = '\0';
	while (*str && *str == c)
		str++;
	*s = str;
	return (ret);
}

static void		clean_mem(char ***cln)
{
	size_t	i;

	i = 0;
	while ((*cln)[i])
	{
		free((*cln)[i]);
		i++;
	}
	free(*cln);
}

char			**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	i2;

	if (!s)
		return (NULL);
	while (*s == c && *s)
		s++;
	i2 = 0;
	i = calc(s, c);
	arr = malloc(sizeof(char*) * (i + 1));
	if (!arr)
		return (NULL);
	while (i2 < i && *s)
	{
		arr[i2] = get_next_str(&s, c);
		if (arr[i2] == NULL)
		{
			clean_mem(&arr);
			return (NULL);
		}
		i2++;
	}
	arr[i2] = (char*)NULL;
	return (arr);
}
