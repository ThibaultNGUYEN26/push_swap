/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:30:18 by thibnguy          #+#    #+#             */
/*   Updated: 2023/02/20 21:28:02 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rrotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*prev_node;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		prev_node = tmp;
		tmp = tmp->next;
	}
	prev_node->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}
