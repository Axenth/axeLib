/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:29:47 by jlensing      #+#    #+#                 */
/*   Updated: 2019/11/15 14:00:11 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char	*c1;
	unsigned const char	*c2;

	c1 = (unsigned const char *)s1;
	c2 = (unsigned const char *)s2;
	while (n > 0)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		if (!*c1 && *c1 == *c2)
			return (0);
		c1++;
		c2++;
		n--;
	}
	return (0);
}
