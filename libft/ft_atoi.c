/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:31:53 by bshawn            #+#    #+#             */
/*   Updated: 2021/08/14 18:42:59 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

long	ft_atoi(char *c)
{
	int						i;
	int						checkminus;
	long					res;

	checkminus = 0;
	i = 0;
	res = 0;
	while (((c[i] >= 8) && (c[i] <= 13)) || c[i] == 32)
		i++;
	if (c[i] == '-' || c[i] == '+')
	{	
		if (c[i] == '-')
			checkminus = 1;
		i++;
	}
	while ((c[i] >= '0') && (c[i] <= '9'))
	{
		res = res * 10 + (c[i] - '0');
		i++;
	}
	if (checkminus == 1)
		res = -res;
	return (res);
}
