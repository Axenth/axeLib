/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 19:34:06 by jlensing       #+#    #+#                */
/*   Updated: 2020/02/01 14:20:36 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*first;

	if (lst == NULL)
		return (NULL);
	first = ft_lstnew((*f)(lst->content));
	if (first == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (new == NULL)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
