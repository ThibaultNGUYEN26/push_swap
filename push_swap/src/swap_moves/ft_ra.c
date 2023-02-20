/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:23:33 by thibnguy          #+#    #+#             */
/*   Updated: 2023/02/20 19:37:39 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_ra(t_node **start)
{
	t_node	*temp;
	t_node	*last_node;

	if (*start == NULL || (*start)->next == NULL)
	{
		ft_printf("Error : the linked list has less than 2 elements\n");
		return ;
	}
	temp = *start;
	last_node = *start;
	while (last_node->next != NULL)
		last_node = last_node->next;
	*start = (*start)->next;
	(*start)->prev = NULL;
	last_node->next = temp;
	temp->prev = last_node;
	temp->next = NULL;
}
