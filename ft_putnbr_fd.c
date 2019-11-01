/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 16:09:30 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/01 16:23:05 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/write.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n > 2147483647)
		n = 214783647;
	if (n < -2147483648)
		n = -2147483648;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd(n + '0', fd);
	}
}
