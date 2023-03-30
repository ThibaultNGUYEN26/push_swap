/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:19:58 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/29 18:50:15 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_double_op(t_node **a, t_node **b, int test)
{
	if (test == 1)
	{
		ft_swap(a, "");
		ft_swap(b, "");
	}
	else if (test == 2)
	{
		ft_rotate(a, "");
		ft_rotate(b, "");
	}
	else if (test == 3)
	{
		ft_rrotate(a, "");
		ft_rrotate(b, "");
	}
}

void	ft_basic_options(t_node **a, t_node **b, char *buf)
{
	if (ft_strcmp(buf, "sa\n") == 0)
		ft_swap(a, "");
	else if (ft_strcmp(buf, "pa\n") == 0)
		ft_push(b, a, "");
	else if (ft_strcmp(buf, "ra\n") == 0)
		ft_rotate(a, "");
	else if (ft_strcmp(buf, "rra\n") == 0)
		ft_rrotate(a, "");
	else if (ft_strcmp(buf, "sb\n") == 0)
		ft_swap(b, "");
	else if (ft_strcmp(buf, "pb\n") == 0)
		ft_push(a, b, "");
	else if (ft_strcmp(buf, "rb\n") == 0)
		ft_rotate(b, "");
	else if (ft_strcmp(buf, "rrb\n") == 0)
		ft_rrotate(b, "");
	else if (ft_strcmp(buf, "ss\n") == 0)
		ft_double_op(a, b, 1);
	else if (ft_strcmp(buf, "rr\n") == 0)
		ft_double_op(a, b, 2);
	else if (ft_strcmp(buf, "rrr\n") == 0)
		ft_double_op(a, b, 3);
	else
		ft_printf("[ERROR] Invalid input, type valid operation.\n");
}
