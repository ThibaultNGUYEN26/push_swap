/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:56:38 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/27 17:25:56 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_free_sorted(t_node **a, int i)
{
	if (ft_sorted(a) && i == 1)
		return (1);
	return (0);
}

static void	ft_min_last_half(t_node **a, t_node *min)
{
	while ((*a)->el != (min)->el)
		ft_rrotate(a, "a");
}

static void	ft_min_first_half(t_node **a, t_node *min)
{
	while ((*a)->el != (min)->el)
		ft_rotate(a, "a");
}

static int	ft_find_min(t_node **a, t_node **b, t_node	*first_a, int i)
{
	t_node	*min;

	while (++i <= 2)
	{
		min = ft_new_stack((ft_min(a))->el);
		if (ft_closest_min(a, min))
			ft_min_last_half(a, min);
		else
			ft_min_first_half(a, min);
		first_a = *a;
		if (ft_free_sorted(a, i))
		{
			free(min);
			min = NULL;
			return (0);
		}
		*a = first_a;
		free(min);
		min = NULL;
		ft_push(a, b, "b");
	}
	free(min);
	min = NULL;
	return (1);
}

void	*ft_sort5(t_node **a, t_node **b)
{
	t_node	*first_a;
	int		size;
	int		i;

	first_a = *a;
	if (ft_sorted(a))
		return (NULL);
	i = 0;
	if (!ft_find_min(a, b, first_a, i))
		return (NULL);
	size = ft_size_stack(a);
	if (size == 3)
		ft_sort3(a);
	if (size == 2)
		ft_sort2(a);
	ft_push(b, a, "a");
	ft_push(b, a, "a");
	return (NULL);
}
