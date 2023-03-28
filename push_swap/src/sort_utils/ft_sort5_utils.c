/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:42:42 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/27 17:27:19 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*ft_min(t_node **s)
{
	t_node	*min;
	t_node	*first;

	min = *s;
	first = *s;
	while ((*s)->next != first)
	{
		*s = (*s)->next;
		if ((*s)->el < min->el)
			min = *s;
	}
	*s = first;
	return (min);
}

int	ft_closest_min(t_node **s, t_node *min)
{
	int		count;
	t_node	*first;
	int		size;

	count = 0;
	first = *s;
	size = ft_size_stack(s);
	while ((*s)->el != min->el)
	{
		count++;
		*s = (*s)->next;
	}
	*s = first;
	if (count > size / 2)
		return (1);
	else
		return (0);
}

int	ft_sorted(t_node **s)
{
	t_node	*first_s;

	first_s = *s;
	while (1)
	{
		if ((*s)->el > (*s)->next->el)
		{
			*s = first_s;
			return (0);
		}
		*s = (*s)->next;
		if ((*s)->next == first_s)
		{
			*s = (*s)->next;
			return (1);
		}
	}
}
