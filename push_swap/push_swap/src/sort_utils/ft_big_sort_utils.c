/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:37:09 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/27 17:23:54 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_exists(int *tab, int size, int el)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == el)
			return (1);
		i++;
	}
	return (0);
}

int	*ft_pack_min(t_node **a)
{
	t_node	*first_a;
	int		min;
	int		*tab_min;
	int		i;		

	i = 0;
	first_a = *a;
	tab_min = malloc(sizeof(int) * ft_size_stack(a));
	if (!tab_min)
		return (NULL);
	while (i < ft_size_stack(a))
	{
		while (ft_exists(tab_min, i, (*a)->el))
			*a = (*a)->next;
		min = (*a)->el;
		*a = (*a)->next;
		while (*a != first_a)
		{
			if ((*a)->el < min && !ft_exists(tab_min, i, (*a)->el))
				min = (*a)->el;
			*a = (*a)->next;
		}
		tab_min[i++] = min;
	}
	return (tab_min);
}

int	ft_idx(int *tab, int size, int element, int index)
{
	int	i;

	i = index;
	while (i < size)
	{
		if (tab[i] == element)
			return (1);
		i++;
	}
	return (0);
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
		if (max->el < (*a)->el)
			max = *a;
		*a = (*a)->next;
	}
	return (max);
}
