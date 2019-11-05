/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 12:49:40 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/02 13:52:54 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int ch)
{
	if (ch >= 97 && ch <= 122)
		ch -= 32;
	return (ch);
}
