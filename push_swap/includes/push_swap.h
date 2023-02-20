/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:57:08 by thibnguy          #+#    #+#             */
/*   Updated: 2023/02/20 19:55:11 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

int		ft_printf(const char *s, ...);
int		ft_intlen(long n, char *base);
size_t	ft_strlen(char *s);
int		ft_atoi(char *nptr);
void	ft_swap(t_node **start);
void	ft_rotate(t_node **start);
void	ft_rrotate(t_node **start);
void	ft_push(t_node **stack_a, t_node **stack_b);

#endif
