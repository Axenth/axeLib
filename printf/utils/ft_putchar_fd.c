/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 19:17:00 by jlensing      #+#    #+#                 */
/*   Updated: 2020/01/10 16:58:34 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include <unistd.h>

struct s_info	ft_putchar_fd(int fd, char c, struct s_info info)
{
	ssize_t i;

	i = write(fd, &c, sizeof(char));
	if (i < 0)
		info.error = e_true;
	return (info);
}
