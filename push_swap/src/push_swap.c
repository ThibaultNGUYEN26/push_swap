/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:14:20 by thibnguy          #+#    #+#             */
/*   Updated: 2023/02/20 19:30:52 by thibnguy         ###   ########.fr       */
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
	t_node	*node;
	int		i;

	node = NULL;
	i = 0;
	if (argc > 1)
	{
		while (++i != argc)
			addlast_node(&node, ft_atoi(argv[i]));
		ft_printf("Linked list : ");
		print_list(node);
		ft_sa(&node);
		ft_printf("sa          : ");
		print_list(node);
		ft_ra(&node);
		ft_printf("ra          : ");
		print_list(node);
		ft_rra(&node);
		ft_printf("rra         : ");
		print_list(node);
	}
	free_list(node);
	return (0);
}
