/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:59:57 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/26 20:44:10 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = n;
	if (ft_strlen((char *)str1) < ft_strlen((char *)str2))
		return (NULL);
	if ((str2 != NULL) && (str2[0] == '\0'))
		return ((char *) str1);
	if ((str1 == NULL) || (str2 == NULL))
		return (NULL);
	while ((str1[i] != '\0') && k >= ft_strlen((char *)str2))
	{
		if ((ft_strncmp((char *)str1 + i,
					(char *)str2, ft_strlen((char *) str2)) == 0))
		{
			return ((char *)str1 + i);
		}
		k--;
		i++;
	}
	return (NULL);
}
