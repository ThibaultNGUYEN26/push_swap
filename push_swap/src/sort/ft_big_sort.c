/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:31:40 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/16 20:01:53 by thibnguy         ###   ########.fr       */
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
		i = -1;
		first = *a;
		ft_pack_max(a, pack_size, tab, position);
		*a = first;
		position += pack_size - 1;
		while (++i < pack_size)
		{
			if (!ft_exists(tab, position + 1, (*a)->content))
				ft_push(a, b, "b");
			else
				ft_rotate(a, "a");
		}
		if (size == 1)
			while (ft_exists(tab, position + 1, (*a)->content))
				ft_rotate(a, "a");
		while (1)
		{
			max = ft_max_stack(b);
			min = ft_min_stack(b);
			if (*b == (*b)->next)
			{
				ft_push(b, a, "a");
				if (size == 0)
					ft_rotate(a, "a");
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
		while (!ft_exists(tab, position, (*a)->content))
			ft_rotate(a, "a");
		size++;
	}
	max = ft_new_stack((ft_max_stack(a))->content);
	first = *a;
	i = -1;
	while (++i < 9)
		*a = (*a)->next;
	*a = (first)->prev;
	while ((*a)->content != (max)->content)
	{
		*a = (*a)->next;
		ft_rrotate(a, "a");
		ft_push(a, b, "b");
		*a = (*a)->prev;
	}
	*a = (*a)->next;
	free(max);
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
	free(tab);
}
