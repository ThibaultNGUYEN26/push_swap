/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:01:34 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/07 13:02:55 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_delete_end(t_node **s)
{
	t_node	*last;
	t_node	*ex;

	if (*s == NULL)
		return ;
	if ((*s)->next == *s)
	{
		free(*s);
		*s = NULL;
		return ;
	}
	last = (*s)->prev;
	ex = (*s)->prev;
	((last)->prev)->next = *s;
	(*s)->prev = (last)->prev;
	free(ex);
	ex = NULL;
}
