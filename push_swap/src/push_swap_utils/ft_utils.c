/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:59:17 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/30 18:50:56 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	addlast_node(t_node **stack, t_node *new_node)
{
	if (*stack == NULL)
	{
		*stack = new_node;
		(*stack)->next = *stack;
		(*stack)->prev = *stack;
		return ;
	}
	((*stack)->prev)->next = new_node;
	(new_node)->prev = (*stack)->prev;
	(new_node)->next = *stack;
	(*stack)->prev = new_node;
}

int	ft_check_arguments(int argc, char *argv[])
{
	if (!ft_check_number(argc, argv)
		|| !ft_check_limit(argc, argv)
		|| !ft_check_duplicate(argc, argv))
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	return (0);
}
