/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:58:55 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/07 13:03:10 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_insert_end(t_node **s, t_node *new)
{
	if (*s == NULL)
	{
		*s = new;
		(*s)->next = *s;
		(*s)->prev = *s;
		return ;
	}
	((*s)->prev)->next = new;
	(new)->prev = (*s)->prev;
	(new)->next = (*s);
	(*s)->prev = new;
}
