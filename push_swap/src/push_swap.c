/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:14:20 by thibnguy          #+#    #+#             */
/*   Updated: 2023/02/20 20:11:37 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	*addlast_node(t_node **node_ref, int content)
{
	struct s_node	*new_node;
	struct s_node	*current_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	if (!(*node_ref))
	{
		*node_ref = new_node;
		return (new_node);
	}
	current_node = *node_ref;
	while (current_node->next)
		current_node = current_node->next;
	current_node->next = new_node;
	return (new_node);
}

static void	print_list(t_node *node)
{
	while (node != NULL)
	{
		ft_printf("%d ", node->content);
		node = node->next;
	}
	printf("\n");
}

static void	free_list(t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 0;
	if (argc > 1)
	{
		while (++i != argc)
			addlast_node(&a, ft_atoi(argv[i]));
		ft_printf("Linked list : ");
		print_list(a);
		ft_swap(&a);
		ft_printf("sa        a : ");
		print_list(a);
		ft_printf("          b : ");
		print_list(b);
		/* ft_push(&b, &a);
		ft_printf("pa        a : ");
		print_list(a);
		ft_printf("          b : ");
		print_list(b);
		ft_rotate(&a);
		ft_printf("ra        a : ");
		print_list(a);
		ft_printf("          b : ");
		print_list(b);
		ft_push(&b, &a);
		ft_printf("pa        a : ");
		print_list(a);
		ft_printf("          b : ");
		print_list(b);
		ft_swap(&a);
		ft_printf("sa        a : ");
		print_list(a);
		ft_printf("          b : ");
		print_list(b);
		ft_push(&b, &a);
		ft_printf("pb        a : ");
		print_list(a);
		ft_printf("          b : ");
		print_list(b);
		ft_push(&b, &a);
		ft_printf("pb        a : ");
		print_list(a);
		ft_printf("          b : ");
		print_list(b);
		ft_rrotate(&b);
		ft_printf("rrb       a : ");
		print_list(a);
		ft_printf("          b : ");
		print_list(b);
		ft_push(&a, &b);
		ft_printf("pa        a : ");
		print_list(a);
		ft_printf("          b : ");
		print_list(b);
		ft_push(&a, &b);
		ft_printf("pa        a : ");
		print_list(a);
		ft_printf("          b : ");
		print_list(b);
		ft_push(&a, &b);
		ft_printf("pa        a : ");
		print_list(a);
		ft_printf("          b : ");
		print_list(b);
		ft_push(&a, &b);
		ft_printf("pa        a : ");
		print_list(a);
		ft_printf("          b : ");
		print_list(b); */
	}
	free_list(a);
	free_list(b);
	return (0);
}
