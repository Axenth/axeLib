/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:52:49 by jlensing       #+#    #+#                */
/*   Updated: 2019/10/28 17:58:39 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 40 && c <= 47)
		return (1);
	if (c >= 50 && c <= 57)
		return (1);
	if (c >= 60 && c <= 67)
		return (1);
	if (c >= 70 && c <= 77)
		return (1);
	if (c >= 100 && c <= 107)
		return (1);
	if (c >= 110 && c <= 117)
		return (1);
	if (c >= 120 && c <= 127)
		return (1);
	if (c >= 130 && c <= 137)
		return (1);
	if (c >= 140 && c <= 147)
		return (1);
	if (c >= 150 && c <= 157)
		return (1);
	if (c >= 160 && c <= 167)
		return (1);
	if (c >= 170 && c <= 176)
		return (1);
	return (0);
}
