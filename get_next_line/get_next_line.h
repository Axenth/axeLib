/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 18:45:59 by jlensing      #+#    #+#                 */
/*   Updated: 2020/04/06 19:10:26 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <stdlib.h>
# include <unistd.h>

char	*gnl_ft_substr(char const *s, unsigned int start, size_t len);
size_t	gnl_ft_strlen(const char *str);
size_t	gnl_ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	gnl_ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*gnl_ft_strjoin(char *s1, char *s2);
char	*gnl_ft_strdup(const char *s1, char *temp, int flag);
int		get_next_line(int fd, char **line);

#endif
