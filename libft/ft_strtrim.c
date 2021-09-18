/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:55:25 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/28 00:19:31 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_must_be_trimmed(char s1, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if ((unsigned char)s1 == (unsigned char) set[i])
			return (1);
		i++;
	}
	return (0);
}

static	int	start_count(char *s1_1, char *set_1)
{
	size_t	start;

	start = 0;
	while (is_must_be_trimmed(s1_1[start], set_1))
	{
		if (start > ft_strlen(s1_1))
			return (0);
		start++;
	}
	return (start);
}

static	int	end_count(char *s1_1, char *set_1)
{
	int	end;

	end = ft_strlen(s1_1) - 1;
	while (is_must_be_trimmed(s1_1[end], set_1))
	{
		if (end <= 0)
			return (0);
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*res;
	int				start;
	int				end;

	if ((!s1) || (!set))
		return (NULL);
	if (!ft_strlen((char *)set))
	{
		res = ft_substr((char *)s1, 0, ft_strlen((char *)s1));
		return (res);
	}
	if (!ft_strlen((char *)s1))
	{
		res = malloc(1);
		if (res == NULL)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	start = start_count((char *)s1, (char *)set);
	end = end_count((char *)s1, (char *)set);
	res = ft_substr((char *)s1, start, (end - start + 1));
	return (res);
}
