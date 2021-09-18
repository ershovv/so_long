/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:41:51 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/26 20:43:38 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t			i;
	char			*res;
	char			*t_str;

	i = 0;
	t_str = ((char *) str);
	res = malloc(ft_strlen(t_str) + 1);
	if (res == NULL)
		return (NULL);
	while (i != ft_strlen(t_str))
	{
		res[i] = t_str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
