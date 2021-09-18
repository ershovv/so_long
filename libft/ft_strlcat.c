/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:29:10 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/21 18:13:54 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	dst_s;

	if (n == 0)
		return (ft_strlen(src));
	dst_s = ft_strlen(dst);
	if (dst_s >= n)
		return (n + ft_strlen(src));
	k = 0;
	i = dst_s;
	while ((i < n) && src[k] != '\0')
	{
		dst[i++] = src[k++];
	}
	if (i == n)
		dst[i - 1] = 0;
	else
		dst[i] = 0;
	return (dst_s + ft_strlen(src));
}
