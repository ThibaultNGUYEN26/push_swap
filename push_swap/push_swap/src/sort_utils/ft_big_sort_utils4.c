/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort_utils4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:35:20 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/27 17:36:14 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_nb_pack(int size)
{
	int	nb_pack;

	if (size > 100)
		nb_pack = 8;
	else
		nb_pack = 5;
	return (nb_pack);
}

void	ft_final_push(t_node **a, t_node **b, int *tab_min, int range)
{
	int	fix_size;
	int	max;

	fix_size = ft_size_stack(a);
	while (ft_size_stack(b) - 1)
	{
		max = ft_max_range(b, range);
		if (((*b)->next)->el == max)
			ft_swap(b, "b");
		else
			ft_b_range(b, max, range);
		while ((*b)->el > (*a)->el)
			ft_rotate(a, "a");
		while ((*b)->el < ((*a)->prev)->el
			&& ((*a)->prev)->el != tab_min[fix_size - 1])
			ft_rrotate(a, "a");
		ft_push(b, a, "a");
	}
	ft_push(b, a, "a");
}
