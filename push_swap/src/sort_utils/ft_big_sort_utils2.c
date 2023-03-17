/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:45:22 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/17 12:55:47 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_not_in_tab_index(int *tab, int size, int element, int index)
{
	int	i;

	i = index;
	while (i < size)
	{
		if (tab[i] == element)
			return (0);
		i++;
	}
	return (1);
}

int	closest_max(t_node **s, int *tab, int position, int index)
{
	int		count_start;
	int		count_end;
	t_node	*first;

	count_start = 0;
	count_end = 0;
	first = *s;
	while (ft_not_in_tab_index(tab, position, (*s)->content, index))
	{
		count_start++;
		*s = (*s)->next;
	}
	*s = (first)->prev;
	while (ft_not_in_tab_index(tab, position, (*s)->content, index))
	{
		count_end++;
		*s = (*s)->prev;
	}
	*s = first;
	if (count_end > count_start)
		return (1);
	else
		return (0);
}

int	ft_distance(t_node **s, t_node *target)
{
	int		count_start;
	int		count_end;
	t_node	*first;

	count_start = 0;
	count_end = 0;
	first = *s;
	while ((*s)->content != target->content)
	{
		count_start++;
		*s = (*s)->next;
	}
	*s = first->prev;
	while ((*s)->content != target->content)
	{
		count_end++;
		*s = (*s)->prev;
	}
	*s = first;
	if (count_start > count_end)
		return (count_end);
	else
		return (count_start);
}

int	ft_end(t_node **s, t_node *target)
{
	int		count_start;
	int		count_end;
	t_node	*first;

	count_start = 0;
	count_end = 0;
	first = *s;
	while ((*s)->content != target->content)
	{
		count_start++;
		*s = (*s)->next;
	}
	*s = first->prev;
	while ((*s)->content != target->content)
	{
		count_end++;
		*s = (*s)->prev;
	}
	*s = first;
	if (count_end > count_start)
		return (1);
	else
		return (0);
}

void	ft_choice(t_node **s, t_node *max, t_node *min)
{
	if (ft_distance(s, max) < ft_distance(s, min))
	{
		ft_print_stack(s, "b");
		if (ft_end(s, max))
		{
			while ((*s)->content != max->content)
				ft_rotate(s, "b");
		}
		else
		{
			while ((*s)->content != max->content)
				ft_rrotate(s, "b");
		}
		ft_print_stack(s, "b");
	}
	else
	{
		ft_print_stack(s, "b");
		if (ft_end(s, min))
		{
			while ((*s)->content != min->content)
				ft_rotate(s, "b");
		}
		else
		{
			while ((*s)->content != (min)->content)
				ft_rrotate(s, "b");
		}
		ft_print_stack(s, "b");
	}	
}
