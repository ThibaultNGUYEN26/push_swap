/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:14:20 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/28 19:10:52 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	int		i;
	int		j;

	a = NULL;
	b = NULL;
	i = 0;
	j = -1;
	if (ft_check_arguments(argc, argv) && argc == 1)
		return (0);
	if (argc >= 2)
		while (++i != argc)
			addlast_node(&a, ft_new_stack(ft_atoi(argv[i])));
	ft_sort(&a, &b);
	return (0);
}
