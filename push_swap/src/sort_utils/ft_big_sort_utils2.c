/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:45:22 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/19 17:30:42 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_search(t_node **s, int max, int min)
{
	t_node	*first;
	int		i;
	int		count_rotate;
	int		count_reverse;

	i = 0;
	first = *s;
	count_rotate = 0;
	count_reverse = 0;
	while (1)
	{
		if ((*s)->content == max || (*s)->content == min)
			break ;
		count_rotate++;
		*s = (*s)->next;
	}
	*s = (first)->prev;
	while (1)
	{
		if ((*s)->content == max || (*s)->content == min)
			break ;
		count_reverse++;
		*s = (*s)->prev;
	}
	*s = first;
	if (count_rotate <= count_reverse)
	{
		i = count_rotate;
		count_rotate = 0;
		while (i && count_rotate++ < i)
			ft_rotate(s, "b");
	}
	else if (count_rotate > count_reverse)
	{
		i = count_reverse + 1;
		count_rotate = 0;
		while (count_rotate++ < i)
			ft_rrotate(s, "b");
	}
}

int	ft_exists_index(int *tab, int size, int element, int index)
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
