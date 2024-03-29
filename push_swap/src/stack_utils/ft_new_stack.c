/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:58:02 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/27 17:27:03 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*ft_new_stack(int el)
{
	t_node	*new;

	new = malloc(sizeof(t_node) * 1);
	if (!new)
		return (NULL);
	new->next = new;
	new->prev = new;
	new->el = el;
	return (new);
}
