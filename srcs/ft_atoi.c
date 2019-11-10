/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:08:31 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/10 16:42:28 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	skip(const char *str, int i)
{
	while (str[i] == '\t' || str[i] == '\b' || str[i] == ' ' || str[i] == '\v'
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
		i++;
	return (i);
}

static int	is_negative(const char *str, int i)
{
	if (str[i] == '-')
		return (-1);
	return (1);
}

int			ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long		result;
	long		max;

	max = 9223372036854775807;
	result = 0;
	i = skip(str, 0);
	sign = is_negative(str, i);
	if (sign == -1)
		i++;
	if (str[i] == '+')
	{
		if (sign == -1)
			return (0);
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
