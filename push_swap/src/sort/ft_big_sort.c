/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:31:40 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/26 19:16:04 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_big_sort(t_node **a, t_node **b)
{
	int		nb_elements;
	int		size;
	int		original_size;
	int		i;
	int		j;
	int		*tab_min;
	int		nb_pack;
	int		pack_size;
	int		max;
	int		iteration;
	int		size_closest;

	if (ft_sorted(a))
		return ;
	size = ft_size_stack(a);
	original_size = size;
	nb_elements = size;
	if (size > 100)
		nb_pack = 8;
	else if (size <= 100)
		nb_pack = 5;
	pack_size = size / nb_pack + (size % nb_pack != 0);
	tab_min = ft_pack_min(a);
	i = 0;
	j = 0;
	while (i++ < nb_pack)
	{
		size = 0;
		if ((i == nb_pack) && (original_size % nb_pack != 0))
		{
			size_closest = nb_elements - 5;
			pack_size = nb_elements - (pack_size * (i - 1));
		}
		else
			size_closest = i * pack_size;
		while (size++ < pack_size)
		{
			if (ft_size_stack(a) == 5)
			{
				ft_sort5(a, b);
				break ;
			}
			ft_closest(a, tab_min, size_closest, size_closest - pack_size);
			while (ft_exists_index(tab_min, nb_elements, (*a)->content, nb_elements - 5))
				ft_rotate(a, "a");
			if (ft_exists_index(tab_min, j + (9 * pack_size / 20), (*a)->content, j))
			{
				ft_push(a, b, "b");
				if (ft_size_stack(b) != 0)
					ft_rotate(b, "b");
			}
			else if (ft_exists_index(tab_min, j + pack_size, (*a)->content, j + (9 * pack_size / 20)))
				ft_push(a, b, "b");
		}
		j += pack_size;
	}
	pack_size = original_size / nb_pack + (original_size % nb_pack != 0);
	if (ft_size_stack(b) % pack_size != 0)
	{
		iteration = ft_size_stack(b) % pack_size;
		i = 0;
		while (i < iteration)
		{
			ft_locate(b, (ft_max_stack(b))->content);
			ft_push(b, a, "a");
			i++;
		}
	}
	int	range = (pack_size / 9) + (pack_size % 9 != 0);
	while (ft_size_stack(b) - 1)
	{
		max = ft_max_range(b, range);
		if (((*b)->next)->content == max)
			ft_swap(b, "b");
		else
			ft_b_range(b, max, range);
		while ((*b)->content > (*a)->content)
			ft_rotate(a, "a");
		while ((*b)->content < ((*a)->prev)->content && ((*a)->prev)->content != tab_min[original_size - 1])
			ft_rrotate(a, "a");
		ft_push(b, a, "a");
	}
	ft_push(b, a, "a");
	//06.30.43.73.70 : Mr benguigui
	// ft_print_stack(a, "a");
	free(tab_min);
}
