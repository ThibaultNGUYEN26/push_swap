/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:45:22 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/27 17:23:43 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_iter_rotate(t_node **s, int max)
{
	t_node	*first;
	int		count_rotate;

	first = *s;
	count_rotate = 0;
	while (1)
	{
		if ((*s)->el == max)
			break ;
		count_rotate++;
		*s = (*s)->next;
	}
	*s = first;
	return (count_rotate);
}

static int	ft_iter_reverse(t_node **s, int max)
{
	t_node	*first;
	int		count_reverse;

	first = *s;
	*s = (first)->prev;
	count_reverse = 0;
	while (1)
	{
		if ((*s)->el == max)
			break ;
		count_reverse++;
		*s = (*s)->prev;
	}
	*s = first;
	return (count_reverse);
}

void	ft_search(t_node **s, int max, int min)
{
	t_node	*first;
	int		count_rotate;
	int		count_reverse;

	first = *s;
	count_rotate = 0;
	count_reverse = 0;
	while ((*s)->el != max && (*s)->el != min)
	{
		count_rotate++;
		*s = (*s)->next;
	}
	*s = first;
	if (count_rotate == 0)
		return ;
	*s = (first)->prev;
	while ((*s)->el != max && (*s)->el != min)
	{
		count_reverse++;
		*s = (*s)->prev;
	}
	*s = first;
	ft_decide_rotate(s, "b", count_rotate, count_reverse);
}

void	ft_closest(t_node **a, int *tab, int pack_size, int index)
{
	t_node	*first_a;
	int		count_rotate;
	int		count_reverse;

	first_a = *a;
	count_reverse = 0;
	count_rotate = 0;
	while (!ft_idx(tab, pack_size, (*a)->el, index))
	{
		count_rotate++;
		*a = (*a)->next;
	}
	*a = (first_a)->prev;
	while (!ft_idx(tab, pack_size, (*a)->el, index))
	{
		count_reverse++;
		*a = (*a)->prev;
	}
	*a = first_a;
	ft_decide_rotate(a, "a", count_rotate, count_reverse);
}

void	ft_locate(t_node **s, int max)
{
	int	count_rotate;
	int	count_reverse;

	count_rotate = ft_iter_rotate(s, max);
	if (count_rotate == 0)
		return ;
	count_reverse = ft_iter_reverse(s, max);
	ft_decide_rotate(s, "b", count_rotate, count_reverse);
}
