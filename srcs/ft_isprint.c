/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:52:49 by jlensing       #+#    #+#                */
/*   Updated: 2019/10/30 19:25:40 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 040 && c <= 047)
		return (1);
	if (c >= 050 && c <= 057)
		return (1);
	if (c >= 060 && c <= 067)
		return (1);
	if (c >= 070 && c <= 077)
		return (1);
	if (c >= 0100 && c <= 0107)
		return (1);
	if (c >= 0110 && c <= 0117)
		return (1);
	if (c >= 0120 && c <= 0127)
		return (1);
	if (c >= 0130 && c <= 0137)
		return (1);
	if (c >= 0140 && c <= 0147)
		return (1);
	if (c >= 0150 && c <= 0157)
		return (1);
	if (c >= 0160 && c <= 0167)
		return (1);
	if (c >= 0170 && c <= 0176)
		return (1);
	return (0);
}
