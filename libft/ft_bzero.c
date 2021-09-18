/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:37:07 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/18 18:47:23 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dst, size_t n)
{
	char			*t_dst;
	unsigned int	i;

	t_dst = (char *)dst;
	i = 0;
	while (i != n)
	{
		t_dst[i] = 0;
		i++;
	}
}