/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:23:33 by thibnguy          #+#    #+#             */
/*   Updated: 2023/02/20 21:07:15 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rotate(t_node **stack, char *move)
{
	t_node	*tmp;
	t_node	*last_node;

	tmp = *stack;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next = tmp;
	tmp->prev = last_node;
	tmp->next = NULL;
	ft_printf("%s\n", move);
}
