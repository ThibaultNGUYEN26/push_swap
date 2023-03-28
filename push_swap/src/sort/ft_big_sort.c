/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:31:40 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/27 17:35:56 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_check_sort5(t_node **a, t_node **b)
{
	if (ft_size_stack(a) == 5)
	{
		ft_sort5(a, b);
		return (0);
	}
	return (1);
}

static void	ft_pb_rb(t_node **a, t_node **b)
{
	ft_push(a, b, "b");
	if (ft_size_stack(b) != 0)
		ft_rotate(b, "b");
}

static void	ft_init_tab(t_node **a, int *tab, int size)
{
	tab[0] = size;
	tab[1] = ft_nb_pack(size);
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	tab[5] = size / tab[1] + (size % tab[1] != 0);
	if (ft_sorted(a))
		return ;
}

static void	ft_smallest_size(int *tab)
{
	if ((tab[3] == tab[1]) && (tab[0] % tab[1] != 0))
	{
		tab[2] = tab[0] - 5;
		tab[5] = tab[0] - (tab[5] * (tab[3] - 1));
	}
	else
		tab[2] = tab[3] * tab[5];
}

void	ft_big_sort(t_node **a, t_node **b, int size, int *tab)
{
	int	v[6];

	ft_init_tab(a, v, size);
	while (v[3]++ < v[1])
	{
		size = 0;
		ft_smallest_size(v);
		while (size++ < v[5])
		{
			if (ft_check_sort5(a, b) == 0)
				break ;
			ft_closest(a, tab, v[2], v[2] - v[5]);
			while (ft_idx(tab, v[0], (*a)->el, v[0] - 5))
				ft_rotate(a, "a");
			if (ft_idx(tab, v[4] + (9 * v[5] / 20), (*a)->el, v[4]))
				ft_pb_rb(a, b);
			else if (ft_idx(tab, v[4] + v[5], (*a)->el, v[4] + (9 * v[5] / 20)))
				ft_push(a, b, "b");
		}
		v[4] += v[5];
	}
	ft_final_push(a, b, ft_pack_min(a), (v[5] / 9) + (v[5] % 9 != 0));
	free(tab);
}
