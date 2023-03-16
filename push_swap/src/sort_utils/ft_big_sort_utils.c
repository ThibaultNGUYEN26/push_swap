/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:37:09 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/16 19:49:15 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_exists(int *tab, int size, int element)
{
	int	i;

	i = -1;
	while (++i < size)
		if (tab[i] == element)
			return (0);
	return (1);
}

t_node	*ft_max_stack(t_node **a)
{
	t_node	*max;
	t_node	*first;

	max = *a;
	first = *a;
	*a = (*a)->next;
	while (*a != first)
	{
		if (max->content < (*a)->content)
			max = *a;
		*a = (*a)->next;
	}
	return (max);
}

t_node	*ft_min_stack(t_node **a)
{
	t_node	*min;
	t_node	*first;

	min = *a;
	first = *a;
	*a = (*a)->next;
	while (*a != first)
	{
		if ((min)->content > (*a)->content)
			min = *a;
		*a = (*a)->next;
	}
	return (min);
}

int	*ft_pack_max(t_node **a, int pack_size, int *tab_max, int i)
{
	t_node	*first;
	t_node	*max;

	first = *a;
	while (pack_size != 0)
	{
		*a = first;
		while (!ft_exists(tab_max, i, (*a)->content))
			*a = (*a)->next;
		max = *a;
		*a = (*a)->next;
		while (*a != first)
		{
			if (((*a)->content > (max)->content)
				&& ft_exists(tab_max, i, (*a)->content))
				max = *a;
			*a = (*a)->next;
		}
		pack_size--;
		tab_max[i++] = (max)->content;
		if (i == 3)
			break ;
	}
	return (tab_max);
}
