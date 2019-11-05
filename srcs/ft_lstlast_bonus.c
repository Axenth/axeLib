/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 18:37:14 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/05 18:49:39 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *current;

	current = lst;
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
		current = current->next;
	return (current);
}
