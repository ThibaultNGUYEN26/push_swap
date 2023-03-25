/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:58:59 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/24 17:02:29 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(t_node **a, t_node **b)
{
	if (ft_size_stack(a) == 2)
		ft_sort2(a);
	else if (ft_size_stack(a) == 3)
		ft_sort3(a);
	else if (ft_size_stack(a) <= 5)
		ft_sort5(a, b);
	else
		ft_big_sort(a, b);
	ft_free_stack(a);
}
