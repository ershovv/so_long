/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 00:24:49 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/26 20:44:58 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	size_t	i;
	char	*res;
	char	*s_1;

	i = 0;
	s_1 = (char *)s;
	if (s_1 == NULL || f == NULL)
		return (NULL);
	res = malloc(ft_strlen(s_1) + 1);
	if (res == NULL)
		return (NULL);
	while (i != ft_strlen(s_1))
	{
		res[i] = f(i, s_1[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
