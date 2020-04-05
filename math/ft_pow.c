/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pow.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 01:03:06 by jlensing       #+#    #+#                */
/*   Updated: 2020/04/05 20:06:20 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double x, double y)
{
	double temp;

	temp = x;
	while (y != 1)
	{
		temp = temp * x;
		y--;
	}
	return (temp);
}
