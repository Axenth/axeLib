/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 18:14:06 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/05 18:19:05 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list *list;

	if ((list = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->content = content;
	return (list);
}
