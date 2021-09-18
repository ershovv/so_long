/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:01:13 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/20 17:44:12 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	unsigned int	i;
	char			*t_dst;

	t_dst = (char *)dst;
	i = 0;
	while (i != n)
	{
		t_dst[i] = c;
		i++;
	}
	return (t_dst);
}
