/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:31:40 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/19 19:14:05 by thibnguy         ###   ########.fr       */
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
	int		count;
	int		position;
	int		max;
	int		min;
	int		nb_pack;

	if (ft_sorted(a))
		return ;
	size = ft_size_stack(a);
	nb_pack = 0;
	if (size > 100)
		nb_pack = 11;
	else if (size <= 100)
		nb_pack = 5;
	pack_size = size / nb_pack + (size % nb_pack != 0);
	tab = malloc(sizeof(int) * size);
	tab[0] = (ft_max_stack(a))->content;
	size = 0;
	position = 1;
	while (size < nb_pack - 1)
	{
		count = 0;
		if (ft_sorted(a))
		{
			free(tab);
			ft_print_stack(a, "a");
			ft_free_stack(a);
			return ;
		}
		i = 0;
		first = *a;
		if (size == 0)
		{
			ft_pack_max(a, pack_size - 1, tab, position);
			position += pack_size - 1;
		}
		else
		{
			ft_pack_max(a, pack_size, tab, position);
			position += pack_size;
		}
		*a = first;
		while (i < pack_size)
		{
			if (!ft_exists_index(tab, position, (*a)->content, position - pack_size))
			{
				if (size == 0 && count == pack_size - 1)
				{
					if ((*a)->content == tab[pack_size - 1])
						ft_rotate(a, "a");
					else if ((*a)->content != tab[0])
						ft_push(a, b, "b");
				}
				else
					ft_push(a, b, "b");
				i++;
				count++;
			}
			else
				ft_rotate(a, "a");
		}
		if (size != 0)
		{
			while (ft_not_in_tab(tab, position, (*a)->content))
				ft_rotate(a, "a");
		}
		while (1)
		{
			if (*b == (*b)->next)
			{
				ft_push(b, a, "a");
				break ;
			}
			max = (ft_max_stack(b))->content;
			min = (ft_min_stack(b))->content;
			ft_search(b, max, min);
			if ((*b)->content == min)
			{
				ft_push(b, a, "a");
				ft_rotate(a, "a");
			}
			else if ((*b)->content == max)
				ft_push(b, a, "a");
		}
		while (!ft_not_in_tab(tab, position, (*a)->content))
			ft_rotate(a, "a");
		++size;
	}
	first = *a;
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
		if (*b == (*b)->next)
		{
			ft_push(b, a, "a");
			break ;
		}
		max = (ft_max_stack(b))->content;
		min = (ft_min_stack(b))->content;
		ft_search(b, max, min);
		if ((*b)->content == min)
		{
			ft_push(b, a, "a");
			ft_rotate(a, "a");
		}
		else if ((*b)->content == max)
			ft_push(b, a, "a");
	}
	while (ft_not_in_tab(tab, position, (*a)->prev->content))
		ft_rrotate(a, "a");
	free(tab);
	ft_print_stack(a, "a");
	ft_free_stack(a);
}
