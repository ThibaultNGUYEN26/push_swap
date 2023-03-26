/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:36:55 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/25 17:56:26 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_max_range(t_node **s, int range)
{
	t_node	*first;
	int		max;
	int		i;

	i = 0;
	first = *s;
	max = (*s)->content;
	*s = (*s)->next;
	while (i++ < range - 1)
	{
		if ((*s)->content > max)
			max = (*s)->content;
		*s = (*s)->next;
	}
	*s = first->prev;
	i = 0;
	while (i++ < range)
	{
		if ((*s)->content > max)
			max = (*s)->content;
		*s = (*s)->prev;
	}
	*s = first;
	return (max);
}

void	ft_b_range(t_node **s, int max, int range)
{
	t_node	*first;
	int		i;

	i = -1;
	first = *s;
	while (++i < range)
	{
		if ((*s)->content == max)
			break ;
		*s = (*s)->next;
	}
	*s = first;
	if (i == range)
	{
		while ((*s)->content != max)
		{
			// ft_printf("MAX SEARCHED %d\n", max);
			// ft_print_stack(s, "b");
			ft_rrotate(s, "b");
		}
	}
	else
	{
		range = 0;
		while (range++ < i)
			ft_rotate(s, "b");
	}
}
