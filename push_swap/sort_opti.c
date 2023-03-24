/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:32:51 by rchbouki          #+#    #+#             */
/*   Updated: 2023/03/23 17:04:35 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* b : 3 2 5 1 4
from the start : max = 2 et min = 3
from the end : max = 2 et min = 1

for the start [2, 3] -> min = 2
for the end [2, 1] -> min = 1

result = start > end

take end => rrb
take start => rb
until find soit min soit max */

/* 
b : 5 8 1 6 3 9 4 7 2
max : b[2] = 9
min : b[5] = 1
size = 9
2 < 4
5 > 4

index de max, index de min
2 et 5
4 - 2 = 2
4 - 5 = -1
1 < 2 donc min est plus proche
 */

t_stack	*s_max_stack(t_stack **a)
{
	t_stack	*max;
	t_stack	*first;
	
	max = *a;
	first = *a;
	*a = (*a)->next;
	while (*a != first)
	{
		if ((max)->element < (*a)->element)
			max = *a;
		*a = (*a)->next;
	}
	return (max);
}

void	ft_b_locate(t_stack **s, int max, int min)
{
	t_stack	*first;
	int		i;
	int		count_rotate;
	int		count_reverse;
	
	i = 0;
	first = *s;
	count_rotate = 0;
	count_reverse = 0;
	while (1)
	{
		if ((*s)->element == max || (*s)->element == min)
			break ;
		count_rotate++;
		*s = (*s)->next;
	}
	*s = first;
	if (count_rotate == 0)
		return ;
	*s = (first)->prev;
	while (1)
	{
		if ((*s)->element == max || (*s)->element == min)
			break ;
		count_reverse++;
		*s = (*s)->prev;
	}
	*s = first;
	printf("POINTER PROBLEM : %d\n", (*s)->element);
	ft_print_stack(s, "b");
	if (count_rotate <= count_reverse)
	{
		i = count_rotate;
		count_rotate = 0;
		while (i && count_rotate++ < i)
			rotate_stack(s, 2);
	}
	else if (count_rotate > count_reverse)
	{
		i = count_reverse + 1;
		count_rotate = 0;
		printf("i %d\n", i);
		printf("count %d\n", count_rotate);
		while (count_rotate++ < i)
			reverse_rotate(s, 2);
	}
}

int	ft_exists_index(int *tab, int size, int element, int index)
{
	int	i;

	i = index;
	while (i < size)
	{
		printf("current tab element at : %d %d\n", tab[i], i);
		if (tab[i] == element)
			return (1);
		i++;
	}
	return (0);
}
