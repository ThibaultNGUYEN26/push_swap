/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:49:04 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/27 17:27:35 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_push(t_node **a, t_node **b, char *s)
{
	t_node	*a_head;

	a_head = ft_new_stack((*a)->el);
	if (*a == NULL)
		return ;
	ft_delete_start(a);
	ft_insert_start(b, a_head);
	if (ft_strcmp(s, "a") == 0)
		ft_printf("pa\n");
	else if (ft_strcmp(s, "b") == 0)
		ft_printf("pb\n");
}
