/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 16:08:10 by jlensing       #+#    #+#                */
/*   Updated: 2020/03/25 21:56:30 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stddef.h>
# include "../hdrs/ft_printf.h"

struct s_info	ft_putstr_fd_util(int fd, char *str, int n, struct s_info info);
struct s_info	ft_putchar_fd_util(int fd, char c, struct s_info info);
void			ft_putnbr_unsigned_fd(unsigned int n, int fd);
char			*convert_to_hex_util(unsigned long value);
int				ft_tolower_util(int c);
int				ft_toupper_util(int c);
char			*ft_strdup_util(const char *s1);
int				ft_strlen_util(const char *str);
size_t			ft_strlcat_util(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy_util(char *dst, const char *src, size_t dstsize);
char			*ft_strjoin_util(char const *s1, char const *s2);
char			*ft_itoa_util(int n);
char			*ft_itoa_util_unsigned_util(unsigned int n);
int				ft_atoi_util(const char *str);
char			*ft_substr_util(char const *s, unsigned int start, size_t len);
int				ft_strncmp_util(const char *s1, const char *s2, size_t n);

#endif
