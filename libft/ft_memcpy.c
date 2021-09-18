/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:16:25 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/20 20:55:37 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*t_dst;
	char			*t_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	t_dst = (char *)dst;
	t_src = (char *)src;
	while (i != n)
	{
		t_dst[i] = t_src[i];
		i++;
	}
	return (dst);
}
