/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:49:40 by thibnguy          #+#    #+#             */
/*   Updated: 2023/02/20 19:28:07 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sa(t_node **start)
{
	int	temp;

	temp = (*start)->content;
	if (*start == NULL || (*start)->next == NULL)
	{
		ft_printf("Error : the linked list has less than 2 elements\n");
		return ;
	}
	(*start)->content = (*start)->next->content;
	(*start)->next->content = temp;
}
