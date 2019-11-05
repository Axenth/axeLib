/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 18:19:49 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/05 20:11:21 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"
#include <stdlib.h>

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list *new_list;

	new_list = malloc(sizeof(t_list));
	new_list = new;
	new_list->next = *alst;
	*alst = new_list;
}
