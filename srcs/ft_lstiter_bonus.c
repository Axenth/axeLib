/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 19:15:12 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/05 19:17:46 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list *current;

	current = lst;
	while (current != NULL)
	{
		if (current->content != NULL)
			f(current->content);
		current = current->next;
	}
}
