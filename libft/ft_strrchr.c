/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 20:13:27 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/27 11:21:52 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != (unsigned char) '\0')
		i++;
	while (str[i] != (unsigned char) c)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return ((char *)str + i);
}
