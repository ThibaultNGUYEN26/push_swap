/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:30:06 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/08 14:56:56 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort2(t_node **a)
{
	if ((*a)->content > (*a)->next->content)
		ft_swap(a, "a");
	ft_free_stack(a);
}

void	ft_sort3(t_node **a)
{
	t_node	*next;
	t_node	*prev;

	next = (*a)->next;
	prev = (*a)->prev;
	if ((*a)->content > next->content && (*a)->content < prev->content)
	{
		ft_swap(a, "a");
	}
	else if ((*a)->content > next->content && next->content < prev->content)
		ft_rotate(a, "a");
	else if ((*a)->content < next->content && (*a)->content > prev->content)
		ft_rrotate(a, "a");
	else if ((*a)->content < next->content && next->content > prev->content)
	{
		ft_swap(a, "a");
		ft_rotate(a, "a");
	}
	else if ((*a)->content > next->content && next->content > prev->content)
	{
		ft_swap(a, "a");
		ft_rrotate(a, "a");
	}
	ft_free_stack(a);
}
