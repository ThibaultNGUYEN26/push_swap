/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:03:47 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/27 17:25:29 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_print_stack(t_node **node, char *s)
{
	t_node	*first;

	first = *node;
	ft_printf("%s : ", s);
	ft_printf("%d ", (*node)->el);
	*node = (*node)->next;
	while (*node != first)
	{
		ft_printf("%d ", (*node)->el);
		*node = (*node)->next;
	}
	printf("\n");
}
