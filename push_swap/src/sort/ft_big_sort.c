/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:31:40 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/25 03:46:37 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_big_sort(t_node **a, t_node **b)
{
	int	nb_elements;
	int	size;
	int	original_size;
	int	i;
	int	j;
	int	*tab_min;
	int	nb_pack;
	int	pack_size;
	int	pack_perm;
	int	min;
	int	max;
	int	min_size;
	int	iteration;
	int	size_closest;

	if (ft_sorted(a))
		return ;
	size = ft_size_stack(a);
	original_size = size;
	nb_elements = size;
	if (size > 100)
		nb_pack = 10;
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
	size = ft_size_stack(b);
	pack_perm = pack_size;
	iteration = size / pack_size;
	i = 0;
	min_size = size - pack_size;
	min = tab_min[min_size];
	max = tab_min[size - 1];
	int	counter = 0;
	while (i < iteration)
	{
		j = 0;
		while (j++ < pack_size)
		{
			min = tab_min[min_size];
			max = tab_min[size - 1];
			if (nb_pack == 10)
				ft_search(b, max, min);
			else
				ft_locate(b, max);
			ft_push(b, a, "a");
			if ((*a)->content == max)
				size--;
			else
			{
				counter++;
				min_size++;
				ft_rotate(a, "a");
			}
			if (max == min)
				break ;
		}
		while (((*a)->prev)->content != tab_min[original_size - 1])
			ft_rrotate(a, "a");
		if (i == iteration - 1)
			break ;
		i++;
		size = ft_size_stack(b);
		min_size = size - pack_perm;
	}
	// ft_print_stack(a, "a");
	//06.30.43.73.70 : Mr benguigui
	free(tab_min);
}
