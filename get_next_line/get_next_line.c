/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 18:45:55 by jlensing      #+#    #+#                 */
/*   Updated: 2020/04/06 19:10:26 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <limits.h>

static int	find_char(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

static char	*gnl_ft_strrchr(const char *s, int c, char *remainder)
{
	size_t			i;

	i = 0;
	free(remainder);
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			return (gnl_ft_strdup(s + i + 1, NULL, 0));
		}
		i++;
	}
	return (NULL);
}

char		*gnl_ft_strdup(const char *s1, char *temp, int flag)
{
	int		size;
	int		counter;
	char	*dup;

	if (flag == 1)
		free(temp);
	size = 0;
	counter = 0;
	size = gnl_ft_strlen(s1);
	dup = malloc(sizeof(char) * size + 1);
	if (dup == NULL)
		return (NULL);
	while (counter < size)
	{
		dup[counter] = s1[counter];
		counter++;
	}
	dup[counter] = '\0';
	return (dup);
}

static int	get_next_line_loop(int fd, char **line, char *temp, int ret)
{
	static char		buff[BUFFER_SIZE + 1];
	static char		*remainder;

	if (remainder != NULL)
		temp = gnl_ft_strdup(remainder, temp, 1);
	if (temp == NULL)
		return (-1);
	while (ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		temp = gnl_ft_strjoin(temp, buff);
		if (temp == NULL)
			return (-1);
		remainder = gnl_ft_strrchr(temp, '\n', remainder);
		if (remainder != NULL)
		{
			*line = gnl_ft_substr(temp, 0, find_char(temp));
			return ((*line == NULL) ? -1 : 1);
		}
	}
	*line = gnl_ft_substr(temp, 0, gnl_ft_strlen(temp));
	return ((*line == NULL) ? -1 : ret);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	char		*temp;

	temp = gnl_ft_strdup("", NULL, 0);
	if (fd < 0 || !line || BUFFER_SIZE < 1 || temp == NULL)
	{
		if (temp)
			free(temp);
		return (-1);
	}
	ret = get_next_line_loop(fd, line, temp, 1);
	if (ret == -1)
		if (temp != NULL)
			free(temp);
	return (ret);
}
