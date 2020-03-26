/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 19:45:34 by jlensing       #+#    #+#                */
/*   Updated: 2020/02/01 14:20:36 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *current;

	if (del == NULL)
		return ;
	while (*lst)
	{
		current = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(current, *del);
	}
	*lst = NULL;
}
