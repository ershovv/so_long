/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:56:56 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/28 00:19:34 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ar, int c, size_t n)
{
	unsigned int		i;
	char				*t_ar;

	t_ar = (char *)ar;
	i = 0;
	while (i != n)
	{
		if ((unsigned char) t_ar[i] == (unsigned char) c)
			return (t_ar + i);
		i++;
	}
	return (NULL);
}
