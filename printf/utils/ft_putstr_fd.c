/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 19:17:52 by jlensing      #+#    #+#                 */
/*   Updated: 2020/04/06 19:10:26 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/utils.h"

struct s_info	ft_putstr_fd_util(int fd, char *str, int n, struct s_info info)
{
	int i;

	i = 0;
	while (str[i] && i < n)
	{
		info = ft_putchar_fd_util(fd, str[i], info);
		i++;
	}
	return (info);
}
