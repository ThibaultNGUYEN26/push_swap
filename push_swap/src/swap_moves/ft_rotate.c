/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:23:33 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/07 13:03:43 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rotate(t_node **s, char *str)
{
	t_node	*head;

	if (*s == NULL || ((*s)->next == *s))
		return ;
	head = ft_new_stack((*s)->content);
	ft_delete_start(s);
	ft_insert_end(s, head);
	if (ft_strcmp(str, "a") == 0)
		ft_printf("ra\n");
	else if (ft_strcmp(str, "b") == 0)
		ft_printf("rb\n");
}
