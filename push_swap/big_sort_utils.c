/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:54:13 by rchbouki          #+#    #+#             */
/*   Updated: 2023/03/21 22:03:34 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
18 16 15 8 13 11 1 2 12 7 9 4 5 14 3 10 17 6
19 18 16 15 8 13 11 1 2 12 7 9 4 5 14 3 10 17 6

12 7 9 14 10 17 18 16 15 8 13 11 
4 5 6 3 2 1 

1 2 3   4 5 6   7 8 9 10 11 12   13 14 15 16 17 18

0 3
3 6

6 9
9 12

12 15
15 18
*/

int	ft_exists(int *tab, int size, int element)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (element == tab[i])
			return (1);
		i++;
	}
	return (0);
}

int	*ft_pack_min(t_stack **a)
{
	t_stack	*first_a;
	int		min;
	int		*tab_min;
	int		i;		

	i = 0;
	first_a = *a;
	tab_min = malloc(sizeof(int) * s_size(a));
	if (!tab_min)
		return (NULL);
	while (i < s_size(a))
	{
		while (ft_exists(tab_min, i, (*a)->element))
			*a = (*a)->next;
		min = (*a)->element;
		*a = (*a)->next;
		while (*a != first_a)
		{
			if ((*a)->element < min && !ft_exists(tab_min, i, (*a)->element))
				min = (*a)->element;
			*a = (*a)->next;
		}
		tab_min[i++] = min;
		printf("%d ", tab_min[i - 1]);
	}
	printf("\n");
	return (tab_min);
}

void	ft_closest(t_stack **a, int *tab, int pack_size, int index)
{
	t_stack	*first_a;
	int		i;
	int		count_rotate;
	int		count_reverse;

	first_a = *a;
	count_reverse = 0;
	count_rotate = 0;
	printf("TAB : ");
	for (int j = index; j < pack_size; j++)
		printf("%d ", tab[j]);
	printf("\n");
	while (!ft_exists_index(tab, pack_size, (*a)->element, index))
	{
		count_rotate++;
		*a = (*a)->next;
	}
	if (count_rotate == 0)
		return ;
	*a = (first_a)->prev;
	while (!ft_exists_index(tab, pack_size, (*a)->element, index))
	{
		count_reverse++;
		*a = (*a)->prev;
	}
	*a = first_a;
	printf("count_rotate : %d count_reverse : %d\n", count_rotate, count_reverse);
	if (count_rotate <= count_reverse)
	{
		i = 0;
		while (i++ < count_rotate)
			rotate_stack(a, 1);
	}
	else	
	{
		i = 0;
		while (i++ <= count_reverse)
			reverse_rotate(a, 1);	
	}
}

/* 
6 0
12 6
18 12
 */