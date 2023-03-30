/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:26:30 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/29 17:08:10 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_size_stack(t_node **s)
{
	int		size;
	t_node	*first;

	if (*s == NULL)
		return (0);
	size = 1;
	first = *s;
	while ((*s)->next != first)
	{
		size++;
		*s = (*s)->next;
	}
	*s = (*s)->next;
	return (size);
}
