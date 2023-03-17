/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:56:38 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/16 23:00:48 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	*ft_free_sorted(t_node **a, t_node *min, int i)
{
	if (ft_sorted(a) && i == 1)
	{
		ft_free_stack(a);
		return (free(min), min = NULL);
	}
	return (NULL);
}

static void	ft_min_last_half(t_node **a, t_node *min, t_node *first_a, int i)
{
	while ((*a)->content != (min)->content)
		ft_rrotate(a, "a");
	first_a = *a;
	ft_free_sorted(a, min, i);
	*a = first_a;
}

static void	ft_min_first_half(t_node **a, t_node *min, t_node *first_a, int i)
{
	while ((*a)->content != (min)->content)
		ft_rotate(a, "a");
	first_a = *a;
	ft_free_sorted(a, min, i);
	*a = first_a;
}

static void	*ft_find_min(t_node **a, t_node **b, t_node	*first_a, int i)
{
	t_node	*min;

	while (++i <= 2)
	{
		min = ft_new_stack((ft_min(a))->content);
		if (ft_closest_min(a, min))
			ft_min_last_half(a, min, first_a, i);
		else
			ft_min_first_half(a, min, first_a, i);
		free(min);
		min = NULL;
		ft_push(a, b, "b");
	}
	return (min);
}

void	*ft_sort5(t_node **a, t_node **b)
{
	t_node	*first_a;
	int		size;
	int		i;

	first_a = *a;
	if (ft_sorted(a))
		return (ft_free_stack(a), NULL);
	i = 0;
	ft_find_min(a, b, first_a, i);
	size = ft_size_stack(a);
	if (size == 3)
		ft_sort3(a);
	if (size == 2)
		ft_sort2(a);
	ft_push(b, a, "a");
	ft_push(b, a, "a");
	ft_free_stack(a);
	return (NULL);
}
