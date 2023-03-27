/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:49:40 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/27 17:27:52 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap(t_node **stack, char *s)
{
	int	tmp;

	tmp = (*stack)->el;
	(*stack)->el = (*stack)->next->el;
	(*stack)->next->el = tmp;
	if (ft_strcmp(s, "a") == 0)
		ft_printf("sa\n");
	else if (ft_strcmp(s, "b") == 0)
		ft_printf("sb\n");
}
