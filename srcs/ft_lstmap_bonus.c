/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 19:34:06 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/06 13:56:45 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *mapped;
	t_list *tmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	tmp = f(lst);
	mapped = tmp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = f(lst)))
		{
			ft_lstclear(&mapped, del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (mapped);
}
