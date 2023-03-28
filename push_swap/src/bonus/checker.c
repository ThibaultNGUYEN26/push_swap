/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:34:27 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/28 19:27:10 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	int		i;
	char	buf[4];
	int		nbytes;
	int		fd;

	a = NULL;
	b = NULL;
	i = 0;
	if (ft_check_arguments(argc, argv) && argc == 1)
		return (0);
	if (argc >= 2)
		while (++i != argc)
			addlast_node(&a, ft_new_stack(ft_atoi(argv[i])));
	fd = fileno(stdout);
	nbytes = read(fd, buf, sizeof(buf));
	// ft_printf("Vous avez écrit: %s", buf);
	while (1)
	{
		if (nbytes <= 0)
		{
			if (ft_sorted(&a))
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
		fd = fileno(stdout);
		nbytes = read(fd, buf, sizeof(buf));
		// ft_printf("Vous avez écrit: %s", buf);
	}
	return (0);
}
