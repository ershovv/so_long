/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:48:14 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/28 00:19:26 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((dst) && (src))
	{
		if (n > 0)
		{
			while ((i < n - 1) && (src[i]))
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
		return (ft_strlen((char *)src));
	}
	return (0);
}
