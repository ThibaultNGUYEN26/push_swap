/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:53:42 by rchbouki          #+#    #+#             */
/*   Updated: 2023/03/23 17:15:34 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_sort_3(t_stack **s)
{
	t_stack	*next;

	next = (*s)->next;
	if ((*s)->element > (next)->element
		&& ((*s)->element < ((*s)->prev)->element))
		swap_stack(s, 1);
	else if ((*s)->element > (next)->element
		&& (next)->element < ((*s)->prev)->element)
		rotate_stack(s, 1);
	else if ((*s)->element < (next)->element
		&& (*s)->element > ((*s)->prev)->element)
		reverse_rotate(s, 1);
	else if ((*s)->element > (next)->element
		&& (next)->element > ((*s)->prev)->element)
	{
		swap_stack(s, 1);
		reverse_rotate(s, 1);
	}
	else if ((*s)->element < (next)->element
		&& (next)->element > ((*s)->prev)->element)
	{
		swap_stack(s, 1);
		rotate_stack(s, 1);
	}
}

void	*s_sort_5(t_stack **a, t_stack **b)
{
	t_stack	*min;
	t_stack	*first_a;
	int		i;
	int		size;
	
	i = 0;
	first_a = *a;
	if (s_sorted(a))
		return (NULL);
	if (s_size(a) == 2)
	{
		if ((*a)->element > ((*a)->next)->element)
			swap_stack(a, 1);
		return (NULL);
	}
	while (++i <= 2)
	{
		min = s_new_stack((s_min(a))->element);
		if (closest_min(a, min))
		{
			while ((*a)->element != (min)->element)
				reverse_rotate(a, 1);
			first_a = *a;
			if (s_sorted(a) && i == 1)
				return (free(min), min = NULL);
			*a = first_a;
		}
		else
		{
			while ((*a)->element != (min)->element)
				rotate_stack(a, 1);
			first_a = *a;
			if (s_sorted(a) && i == 1)
				return (free(min), min = NULL);
			*a = first_a;
		}
		free(min);
		min = NULL;
		push_stack(b, a, 2);
	}
	size = s_size(a);
	if (size == 3)
		s_sort_3(a);
	if (size == 2)
		s_sort_5(a, b);
	push_stack(a, b, 1);
	push_stack(a, b, 1);
	return (NULL);
}

void	s_big_sort(t_stack **a, t_stack **b)
{
	//t_stack	*first_a;
	int		nb_elements;
	int		size;
	int		original_size;
	int		i;
	int		j;
	int		*tab_min;
	int		nb_pack;
	int		pack_size;

	if (s_sorted(a))
		return ;
	size = s_size(a);
	original_size = size;
	nb_elements = size;
	if (size <= 100)
		nb_pack = 3;
	else
		nb_pack = 5;
	pack_size = size / nb_pack + (size % nb_pack != 0);
	printf("PACK SIZE : %d\n", pack_size);
	tab_min = ft_pack_min(a);
	j = 0;
	i = 0;
	while (i++ < nb_pack)
	{
		ft_print_stack(a, "a");
		size = 0;
		if ((i == nb_pack) && (original_size % nb_pack != 0))
			pack_size = pack_size - (2 * (original_size % nb_pack));
		printf("i : %d PACK_SIZE : %d\n", i, pack_size);
		while (size++ < pack_size)
		{
			if (s_size(a) == 5)
			{
				s_sort_5(a, b);
				printf("SORT 5\n");
				break;
			}
			//first_a = *a;
			ft_print_stack(a, "a");
			ft_closest(a, tab_min, i * pack_size, (i - 1) * pack_size);
			ft_print_stack(a, "a");
			// if 		: j = 6, pack_size = 6, 0 to 3
			// else if : 3 to 6
			printf("j : %d PACK_SIZE : %d\n", j, pack_size);
			printf("MID : %d\n", j + (pack_size / 2));
			while (ft_exists_index(tab_min, nb_elements, (*a)->element, nb_elements - 5))
				rotate_stack(a, 1);
			if (ft_exists_index(tab_min, j + (pack_size / 2), (*a)->element, j))
			{
				printf("FIRST HALF OF THE PACK\n");
				// nb_elements = 18, 13 to 18
				push_stack(b, a, 2);
				if (s_size(b) != 0)
					rotate_stack(b, 2);
			}
			else if (ft_exists_index(tab_min, j + pack_size, (*a)->element, j + (pack_size / 2)))
			{
				printf("SECOND HALF OF THE PACK\n");
				push_stack(b, a, 2);
			}
			ft_print_stack(b, "b");
		}
		j += pack_size;
	}
	/* 
	16 15 13 14 6 5 7 8 1 2 4 3 10 9 12 11 17
	0 1 2 .                          14 15 16
		  3 4 5             11 12 13
		        6 7 8  9 10

	0   3
	14	17

	3   6
	11  14

	6   9
	8   11
	
	taille = pack_size / 2
	j  j + taille
	j += taille

	b_size = 17
	b_size - taille  b_size (17)
	b_size -= taille
	b_size - taille  b_size (14)
    8                11	
	 */
	printf("NEW\n");
	int	iteration;
	pack_size = original_size / nb_pack + (original_size % nb_pack != 0);
	if (s_size(b) % pack_size != 0)
	{
		iteration = s_size(b) % pack_size;
		printf("pack_size : %d\n", pack_size);
		i = 0;
		while (i < iteration)
		{
			if (((*b)->prev)->element == (s_max_stack(b))->element)
				reverse_rotate(b, 2);
			push_stack(a, b, 1);
			i++;
		}
	}
	// TAB = 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
	size = s_size(b);
	int pack_perm = pack_size;
	iteration = size / pack_size;
	i = 0; 
	int	min;
	int	max;
	min = tab_min[size - pack_size]; // 8  0
	max = tab_min[size - 1]; // 15 7
	while (i < iteration)
	{
		j = 0;
		ft_print_stack(b, "b main : ");
		while (j++ < pack_size - 1)
		{
			max = tab_min[size - 1]; // 15 7
			if (max == min)
				break;
			printf("min : %d\n", min);
			printf("max : %d\n", max);
			ft_b_locate(b, max, min);
			push_stack(a, b, 1);
			if ((*a)->element == max)
				size--;
			else
			{
				pack_size++;
				rotate_stack(a, 1);
			}
			ft_print_stack(a, "a");
		}
		while (((*a)->prev)->element != tab_min[original_size - 1])
			reverse_rotate(a, 1);
		if (i == iteration - 1)
			break;
		i++;
		size = s_size(b);
		printf("%d\n", size);
		min = tab_min[size - pack_perm]; // 8  0
		max = tab_min[size - 1]; // 15 7
	}
	free(tab_min);
}
