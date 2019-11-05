/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 19:45:34 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/05 19:58:25 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *current;

	current = *lst;
	while (current != NULL)
	{
		del(current->content);
		current = current->next;
		free(current);
	}
	current = NULL;
}
