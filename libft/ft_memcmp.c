/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:25:48 by bshawn            #+#    #+#             */
/*   Updated: 2021/08/08 15:52:03 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ar1, const void *ar2, size_t n)
{
	unsigned int	i;
	char			*t_ar1;
	char			*t_ar2;

	i = 0;
	t_ar2 = (char *) ar2;
	t_ar1 = (char *) ar1;
	while (i < n)
	{
		if (t_ar1[i] != t_ar2[i])
		{
			return ((unsigned char) t_ar1[i] - (unsigned char) t_ar2[i]);
		}
		i++;
	}
	return (0);
}
