/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:57:08 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/19 17:16:41 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

int		ft_atoi(char *nptr);
int		ft_isdigit(int c);
int		*ft_split(char *s);
int		ft_isinteger(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(char *s);
int		ft_intlen(long n, char *base);
int		ft_printf(const char *s, ...);
int		ft_check_number(int size, char **s);
int		ft_count_words(char *str);
int		ft_str_to_tab(char *str);
int		is_valid_number(char *s);
int		ft_check_limit(int size, char **s);
int		ft_check_duplicate(int size, char **s);
void	ft_print_stack(t_node **node, char *s);
void	ft_sort2(t_node **a);
void	ft_sort3(t_node **a);
void	*ft_sort5(t_node **a, t_node **b);
void	ft_big_sort(t_node **a, t_node **b);
int		ft_not_in_tab(int *tab, int size, int element);
int		ft_not_in_tab_index(int *tab, int size, int element, int index);
t_node	*ft_max_stack(t_node **a);
t_node	*ft_min_stack(t_node **a);
int		*ft_pack_max(t_node **a, int pack_size, int *tab_max, int i);
void	ft_search(t_node **s, int max, int min);
int		ft_exists_index(int *tab, int size, int element, int index);
void	ft_sort(t_node **a, t_node **b);
t_node	*ft_min(t_node **s);
int		ft_closest_min(t_node **s, t_node *min);
int		ft_sorted(t_node **s);
void	ft_delete_end(t_node **s);
void	ft_delete_start(t_node **s);
void	ft_free_stack(t_node **s);
void	ft_insert_end(t_node **s, t_node *new);
void	ft_insert_start(t_node **s, t_node *new);
t_node	*ft_new_stack(int content);
int		ft_size_stack(t_node **s);
void	ft_push(t_node **a, t_node **b, char *s);
void	ft_rotate(t_node **s, char *str);
void	ft_rr(t_node *a, t_node *b);
void	ft_rrotate(t_node **s, char *str);
void	ft_rrr(t_node *a, t_node *b);
void	ft_swap(t_node **start, char *s);
void	ft_ss(t_node *a, t_node *b);

#endif
