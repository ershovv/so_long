/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:44:43 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/21 11:57:44 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*t_dst;
	char			*t_src;

	i = 0;
	t_dst = (char *)dst;
	t_src = (char *)src;
	while (i != n)
	{
		t_dst[i] = t_src[i];
		if ((unsigned char)t_src[i] == (unsigned char) c)
		{
			i++;
			return (t_dst + i);
		}
		i++;
	}
	return (NULL);
}
