/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:30:18 by thibnguy          #+#    #+#             */
/*   Updated: 2023/02/20 19:36:40 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rra(t_node **start)
{
	t_node	*temp;
	t_node	*prev_node;

	if (*start == NULL || (*start)->next == NULL)
	{
		ft_printf("Error : the linked list has less than 2 elements\n");
		return ;
	}
	temp = *start;
	while (temp->next != NULL)
	{
		prev_node = temp;
		temp = temp->next;
	}
	prev_node->next = NULL;
	temp->prev = NULL;
	temp->next = *start;
	(*start)->prev = temp;
	*start = temp;
}
