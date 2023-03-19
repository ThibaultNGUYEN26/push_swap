/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:45:08 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/05 17:49:20 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_insert_start(t_node **s, t_node *new)
{
	if (*s == NULL)
	{
		*s = new;
		(*s)->next = *s;
		(*s)->prev = *s;
		return ;
	}
	(*s)->prev->next = new;
	new->prev = (*s)->prev;
	new->next = *s;
	(*s)->prev = new;
	*s = new;
}
