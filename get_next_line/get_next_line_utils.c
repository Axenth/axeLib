/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 18:45:52 by jlensing       #+#    #+#                */
/*   Updated: 2020/02/01 14:23:54 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*gnl_ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*result;

	if (s == NULL)
		return (NULL);
	s_len = gnl_ft_strlen(s);
	if (s_len - start < len)
		len = s_len - start;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
	{
		free((char *)s);
		return (NULL);
	}
	gnl_ft_strlcpy(result, s + start, len + 1);
	free((char *)s);
	return (result);
}

size_t	gnl_ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	gnl_ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*tdst;
	char		*tend;
	const char	*tsrc;

	tdst = dst;
	tend = dst + dstsize;
	tsrc = src;
	if (src == NULL)
		return (0);
	while (*tsrc != '\0' && tdst < tend)
	{
		*tdst = *tsrc;
		tdst++;
		tsrc++;
	}
	if (tdst < tend)
		*tdst = 0;
	else if (dstsize > 0)
		tdst[-1] = 0;
	while (*tsrc != '\0')
		tsrc++;
	return (tsrc - src);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dstl;
	size_t srcl;

	dstl = gnl_ft_strlen(dst);
	srcl = gnl_ft_strlen(src);
	if (!dstsize || dstsize < dstl)
		return (dstl + srcl - (dstl - dstsize));
	dstsize -= dstl;
	gnl_ft_strlcpy(dst + dstl, src, dstsize);
	return (dstl + srcl);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	size = gnl_ft_strlen(s1);
	size += gnl_ft_strlen(s2);
	size++;
	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	gnl_ft_strlcpy(str, s1, size);
	ft_strlcat(str, s2, size);
	if (s1)
		free(s1);
	return (str);
}
