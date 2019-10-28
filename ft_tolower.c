/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:53:44 by jlensing       #+#    #+#                */
/*   Updated: 2019/10/28 15:31:51 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	ft_tolower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		ch += 32;
	return (ch);
}
