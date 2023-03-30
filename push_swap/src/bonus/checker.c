/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:34:27 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/30 17:34:23 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_check_sorted(t_node **a, t_node **b)
{
	if (ft_size_stack(a) != 0 && ft_sorted(a) && ft_size_stack(b) == 0)
	{
		ft_printf("OK\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_printf("KO\n");
		exit(EXIT_FAILURE);
	}
}

static void	ft_read_op(t_node **a, t_node **b)
{
	char	*buf;
	int		nbytes;

	while (1)
	{
		buf = malloc(sizeof(char) * 4);
		nbytes = read(STDIN_FILENO, buf, sizeof(buf));
		buf[nbytes] = '\0';
		if (nbytes <= 0)
			ft_check_sorted(a, b);
		ft_basic_options(a, b, buf);
		free(buf);
	}
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 0;
	if (ft_check_arguments(argc, argv) == 1)
		exit (1);
	if (argc >= 2)
		while (++i != argc)
			addlast_node(&a, ft_new_stack(ft_atoi(argv[i])));
	ft_read_op(&a, &b);
	return (0);
}
