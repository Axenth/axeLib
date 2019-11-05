/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 18:50:56 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/05 20:30:22 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *current;

	current = *alst;
	if (new == NULL)
		return ;
	if (current != NULL)
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
	}
	else if (current == NULL)
	{
		current = new;
	}
}
