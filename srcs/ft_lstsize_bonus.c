/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 18:21:22 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/05 18:32:22 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	current = lst;
	i = 0;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}
