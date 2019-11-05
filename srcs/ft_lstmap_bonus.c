/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 19:34:06 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/05 20:10:01 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *current;

	current = lst;
	new = NULL;
	while (current != NULL)
	{
		new = malloc(sizeof(t_list));
		if (f(current->content))
		{
			new->content = current->content;
		}
		else
		{
			del(current->content);
			free(current);
		}
		new->next = NULL;
		new = new->next;
		current = current->next;
	}
	return (new);
}
