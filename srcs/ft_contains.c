/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_contains.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:02:44 by jlensing      #+#    #+#                 */
/*   Updated: 2020/06/16 15:11:00 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

int		ft_strcontains(char *str, char *set)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	if (str == NULL || set == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == set[0])
		{
			while (set[j] != '\0')
			{
				if (str[i + j] != set[j])
					break ;
				if (j == ft_strlen(set) - 1)
					return (1);
				j++;
			}
		}
		j = 0;
		i++;
	}
	return (0);
}
