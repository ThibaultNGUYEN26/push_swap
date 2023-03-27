/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:26:37 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/27 17:25:04 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_intlen(long n, char *base)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= ft_strlen(base);
		len++;
	}
	return (len);
}
