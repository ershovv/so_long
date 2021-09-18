/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 21:13:30 by bshawn            #+#    #+#             */
/*   Updated: 2021/09/15 11:16:52 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		i2;
	char	*res;

	if (!s1)
		return (NULL);
	i = 0;
	i2 = 0;
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[i2])
		res[i++] = s2[i2++];
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin_m(char *s1, char const *s2)
{
	int		i;
	int		i2;
	char	*res;

	if (!s1)
		return (NULL);
	i = 0;
	i2 = 0;
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[i2])
		res[i++] = s2[i2++];
	res[i] = '\0';
	free(s1);
	s1 = NULL;
	return (res);
}
