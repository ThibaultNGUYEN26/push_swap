/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:30:06 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/27 17:25:37 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort2(t_node **a)
{
	if ((*a)->el > (*a)->next->el)
		ft_swap(a, "a");
}

void	ft_sort3(t_node **a)
{
	t_node	*next;
	t_node	*prev;

	next = (*a)->next;
	prev = (*a)->prev;
	if ((*a)->el > next->el && (*a)->el < prev->el)
	{
		ft_swap(a, "a");
	}
	else if ((*a)->el > next->el && next->el < prev->el)
		ft_rotate(a, "a");
	else if ((*a)->el < next->el && (*a)->el > prev->el)
		ft_rrotate(a, "a");
	else if ((*a)->el < next->el && next->el > prev->el)
	{
		ft_swap(a, "a");
		ft_rotate(a, "a");
	}
	else if ((*a)->el > next->el && next->el > prev->el)
	{
		ft_swap(a, "a");
		ft_rrotate(a, "a");
	}
}
