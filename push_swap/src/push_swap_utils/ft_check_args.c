/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:29:24 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/15 17:41:54 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_check_number(int size, char **s)
{
	int	i;

	i = 0;
	while (++i < size)
	{
		if (!ft_isinteger(s[i]))
			return (0);
	}
	return (1);
}

int	ft_count_words(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == ' ')
		{
			while (str[++i] == ' ')
				;
			if (str[i] != '\0')
				count++;
		}
	}
	return (count + 1);
}

int	is_valid_number(char *str)
{
	int	n;

	if (*str == '-' || *str == '+')
		++str;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		++str;
	}
	n = ft_atoi(str);
	return (n >= INT_MIN && n <= INT_MAX);
}

int	ft_check_limit(int size, char **s)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(s[i], "2147483647") == 0)
			return (0);
		if (ft_strcmp(s[i], "-2147483648") == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_duplicate(int size, char **s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1)
		{
			if ((i != j) && (ft_strcmp(s[i], s[j]) == 0))
				return (0);
		}
	}
	return (1);
}
