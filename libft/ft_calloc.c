/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:41:20 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/21 18:44:45 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t s)
{
	char			*buf;

	buf = malloc(n * s);
	if (!buf)
		return (NULL);
	ft_bzero(buf, n * s);
	return (buf);
}
