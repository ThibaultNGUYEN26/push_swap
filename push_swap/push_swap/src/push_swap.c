/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:14:20 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/27 14:51:30 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	addlast_node(t_node **stack, t_node *new_node)
{
	if (*stack == NULL)
	{
		*stack = new_node;
		(*stack)->next = *stack;
		(*stack)->prev = *stack;
		return ;
	}
	((*stack)->prev)->next = new_node;
	(new_node)->prev = (*stack)->prev;
	(new_node)->next = *stack;
	(*stack)->prev = new_node;
}

static int	ft_check_arguments(int argc, char *argv[])
{
	if (argc < 2)
		return (0);
	else if (argc > 2)
	{
		if (!ft_check_number(argc, argv)
			|| !ft_check_limit(argc, argv)
			|| !ft_check_duplicate(argc, argv))
		{
			ft_printf("Error\n");
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	int		i;
	int		j;
	int		*tab;

	a = NULL;
	b = NULL;
	i = 0;
	j = -1;
	if (ft_check_arguments(argc, argv))
		return (0);
	if (argc == 2)
	{
		tab = ft_split(argv[1]);
		while (++j < ft_count_words(argv[1]))
			addlast_node(&a, ft_new_stack(tab[j]));
		free(tab);
	}
	else if (argc >= 2)
		while (++i != argc)
			addlast_node(&a, ft_new_stack(ft_atoi(argv[i])));
	ft_sort(&a, &b);
	return (0);
}
