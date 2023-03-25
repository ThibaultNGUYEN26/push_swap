/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:47:25 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/05 17:49:38 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_delete_start(t_node **s)
{
	t_node	*head;
	t_node	*ex;

	if (*s == NULL)
		return ;
	if ((*s)->next == *s)
	{
		free(*s);
		*s = NULL;
		return ;
	}
	head = (*s)->next;
	ex = *s;
	(*s)->prev->next = head;
	head->prev = (*s)->prev;
	*s = head;
	free(ex);
	ex = NULL;
}
