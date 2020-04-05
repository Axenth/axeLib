/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_floor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 02:01:45 by jlensing       #+#    #+#                */
/*   Updated: 2020/04/05 20:07:06 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

double	ft_floor(double x)
{
	long long	temp;
	double		result;

	if (x >= LLONG_MAX || x <= LLONG_MIN || x != x)
		return (x);
	temp = (long long)x;
	result = (double)temp;
	if (result == x || result >= 0)
		return (result);
	else
		return (result - 1);
}
