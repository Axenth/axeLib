/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ceil.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 21:59:01 by jlensing      #+#    #+#                 */
/*   Updated: 2020/04/06 19:10:26 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

double	ft_ceil(double x)
{
	long long	temp;
	double		result;

	if (x >= LLONG_MAX || x <= LLONG_MIN || x != x)
		return (x);
	temp = (long long)x;
	result = (double)temp;
	if (result == x)
		return (result);
	else if (result >= 0)
		return (result + 1);
	else if (result < 0)
		return (result);
	return (result);
}
