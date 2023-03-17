/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:31:40 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/17 13:04:47 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_big_sort(t_node **a, t_node **b)
{
	t_node	*first;
	int		*tab;
	int		size;
	int		pack_size;
	int		i;
	int		position;
	t_node	*max;
	t_node	*min;
	int		k;

	if (ft_sorted(a))
		return ;
	size = ft_size_stack(a);
	if (size % 3 != 0)
		pack_size = (size / 3) + 1;
	else
		pack_size = size / 3;
	tab = malloc(sizeof(int) * size);
	tab[0] = (ft_max_stack(a))->content;
	size = 0;
	position = 1;
	while (size < 2)
	{
		if (ft_sorted(a))
		{
			free(tab);
			ft_print_stack(a, "a");
			ft_free_stack(a);
			return ;
		}
		i = 0;
		first = *a;
		if (size == 1)
			ft_pack_max(a, pack_size, tab, position);
		else
			ft_pack_max(a, pack_size - 1, tab, position);
		*a = first;
		if (size == 0)
			position += pack_size - 1;
		else
			position += pack_size;
		while (i < pack_size)
		{
			if (size == 0)
				k = 0;
			else
				k = pack_size;
			if (!closest_max(a, tab, position, k))
			{
				if (!ft_not_in_tab(tab, position, (*a)->content))
				{
					ft_push(a, b, "b");
					i++;
				}
				else
					ft_rrotate(a, "a");
			}
			else
			{
				if (!ft_not_in_tab(tab, position, (*a)->content))
				{
					ft_push(a, b, "b");
					i++;
				}
				else
					ft_rotate(a, "a");
			}
		}
		if (size == 1)
		{
			while (ft_not_in_tab(tab, position, (*a)->content))
				ft_rotate(a, "a");
		}
		while (1)
		{
			max = ft_max_stack(b);
			min = ft_min_stack(b);
			if (*b == (*b)->next)
			{
				ft_push(b, a, "a");
				break ;
			}
			else if ((*b)->content == (min)->content)
			{
				ft_push(b, a, "a");
				ft_rotate(a, "a");
			}
			else if ((*b)->content == (max)->content)
				ft_push(b, a, "a");
			else
				ft_rotate(b, "b");
				// ft_choice(b, max, min);
		}
		while (!ft_not_in_tab(tab, position, (*a)->content))
			ft_rotate(a, "a");
		size++;
	}
	if (ft_sorted(a))
	{
		free(tab);
		ft_print_stack(a, "a");
		ft_free_stack(a);
		return ;
	}
	while (ft_not_in_tab(tab, position, (*a)->content))
		ft_push(a, b, "b");
	while (1)
	{
		max = ft_max_stack(b);
		min = ft_min_stack(b);
		if (*b == (*b)->next)
		{
			ft_push(b, a, "a");
			break ;
		}
		else if ((*b)->content == (min)->content)
		{
			ft_push(b, a, "a");
			ft_rotate(a, "a");
		}
		else if ((*b)->content == (max)->content)
			ft_push(b, a, "a");
		else
			ft_rotate(b, "b");
	}
	while (ft_not_in_tab(tab, position, (*a)->prev->content))
		ft_rrotate(a, "a");
	free(tab);
	ft_print_stack(a, "a");
	ft_free_stack(a);
}
