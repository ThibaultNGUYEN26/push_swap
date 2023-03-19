/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:02:58 by thibnguy          #+#    #+#             */
/*   Updated: 2023/03/04 18:03:32 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	cmp_1;
	unsigned char	cmp_2;

	i = 0;
	if ((!s1 || !s2) && (!*s1 || !*s2))
		return (0);
	cmp_1 = *s1;
	cmp_2 = *s2;
	while ((s1[i] || s2[i]) && (cmp_1 || cmp_2))
	{
		cmp_1 = (unsigned char)s1[i];
		cmp_2 = (unsigned char)s2[i];
		if (cmp_1 != cmp_2)
			return (cmp_1 - cmp_2);
		i++;
	}
	return (cmp_1 - cmp_2);
}
