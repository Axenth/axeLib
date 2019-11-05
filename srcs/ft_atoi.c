/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:08:31 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/01 14:42:04 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long		result;
	long		max;

	max = 9223372036854775807;
	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\b' || str[i] == ' ' || str[i] == '\v'
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > max / 10)
			return (sign == -1 ? 0 : -1);
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
