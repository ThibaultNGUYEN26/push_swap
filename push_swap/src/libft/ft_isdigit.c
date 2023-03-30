/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:13:42 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/30 18:22:21 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\f' || c == '\r' || c == '0');
}

int	ft_isinteger(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str) && !ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}
