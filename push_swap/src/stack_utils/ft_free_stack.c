/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:32:45 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/27 17:26:40 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_free_stack(t_node **s)
{
	t_node	*tmp;
	t_node	*first;

	first = *s;
	tmp = (*s)->next;
	while (tmp != first)
	{
		tmp = tmp->next;
		free(tmp->prev);
	}
	free(first);
	*s = NULL;
}
