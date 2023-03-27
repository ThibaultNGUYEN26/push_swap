/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:02:03 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/15 17:41:48 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*ft_substr(char *src, int start, int end)
{
	char	*res;
	int		i;

	res = (char *) malloc(sizeof(char) * (end - start));
	if (res == 0)
		return (0);
	i = -1;
	while (++i < (end - start))
		res[i] = src[i + start];
	res[i] = '\0';
	return (res);
}

void	ft_write_split(char *str, char **tab)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		start = i;
		while (str[i] && str[i] != ' ')
			i++;
		if (i != start)
		{
			tab[j] = ft_substr(str, start, i);
			j++;
		}
	}
}

int	*ft_split(char *str)
{
	char	**tab;
	int		*res;
	int		nb_words;
	int		i;

	nb_words = ft_count_words(str);
	tab = (char **) malloc(sizeof(char *) * nb_words);
	if (tab == NULL)
		return (NULL);
	res = malloc(sizeof(int) * nb_words);
	if (res == NULL)
		return (NULL);
	ft_write_split(str, tab);
	tab[nb_words] = NULL;
	i = -1;
	while (++i < nb_words)
		res[i] = ft_atoi(tab[i]);
	i = -1;
	while (++i < nb_words)
		free(tab[i]);
	free(tab);
	return (res);
}
