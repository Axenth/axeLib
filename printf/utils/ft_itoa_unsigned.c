/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_unsigned.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 14:09:27 by jlensing       #+#    #+#                */
/*   Updated: 2020/04/05 20:03:20 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/utils.h"
#include <stdlib.h>

static int		count_amount(unsigned int temp)
{
	unsigned int amount;

	amount = 0;
	while (temp > 0)
	{
		temp /= 10;
		amount++;
	}
	return (amount);
}

static char		*check_value(unsigned int n)
{
	if (n == 0 || n == -0)
		return (ft_strdup_util("0"));
	return (NULL);
}

static char		*calc_result(long n, unsigned int amount)
{
	int		i;
	char	*result;

	result = malloc(amount * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	i = amount - 1;
	while (i >= 0)
	{
		result[i] = n % 10 + '0';
		n /= 10;
		if (!i)
			break ;
		i--;
	}
	return (result);
}

char			*ft_itoa_util_unsigned_util(unsigned int n)
{
	char				*result;
	unsigned int		amount;
	unsigned int		temp;

	temp = n;
	if (n == 0)
		return (check_value(n));
	amount = count_amount(temp);
	result = calc_result(temp, amount);
	if (result == NULL)
		return (NULL);
	result[amount] = '\0';
	return (result);
}
