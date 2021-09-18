/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:14:13 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/21 12:54:45 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*t_dst;
	unsigned const char		*t_src;

	if ((dst == NULL) && (src == NULL))
		return (NULL);
	t_dst = (unsigned char *)dst;
	t_src = (unsigned const char *)src;
	i = 0;
	if (t_dst < t_src)
	{
		while (i < n)
		{
			t_dst[i] = t_src[i];
			i++;
		}
	}
	else
	{
		while (n--)
			t_dst[n] = t_src[n];
	}
	return (t_dst);
}
