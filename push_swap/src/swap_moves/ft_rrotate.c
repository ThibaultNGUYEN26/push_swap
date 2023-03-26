/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:30:18 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/07 13:12:10 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rrotate(t_node **s, char *str)
{
	t_node	*end;

	if (*s == NULL || ((*s)->next == *s))
		return ;
	end = ft_new_stack(((*s)->prev)->content);
	ft_delete_end(s);
	ft_insert_start(s, end);
	if (ft_strcmp(str, "a") == 0)
		ft_printf("rra\n");
	else if (ft_strcmp(str, "b") == 0)
		ft_printf("rrb\n");
}
