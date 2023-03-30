/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:50:39 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/30 18:36:19 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\f' || c == '\r' || c == '0');
}

static int	ft_atoi_overflow(int sign)
{
	if (sign < 0)
		return (0);
	return (-1);
}

static void	ft_check_len(char *nptr)
{
	if (ft_strlen(nptr) > 11)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

long int	ft_atoi(char *nptr)
{
	unsigned long	nbr;
	int				sign;

	while (ft_isspace(*nptr))
		nptr++;
	ft_check_len(nptr);
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	nbr = 0;
	while (ft_isdigit(*nptr))
	{
		if ((nbr * 10 + (*nptr - '0')) / 10 != nbr)
			return (ft_atoi_overflow(sign));
		nbr *= 10;
		nbr += *nptr - '0';
		nptr++;
	}
	return (sign * nbr);
}
