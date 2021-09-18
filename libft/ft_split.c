/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:37:25 by bshawn            #+#    #+#             */
/*   Updated: 2021/08/08 15:51:55 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_extra_strlen(char *s, char c)
{
	int	i;

	i = 0;
	while ((s[i] != c) && (s[i]))
		i++;
	return (i);
}

static	int	mas_count_f(char *s, char c)
{
	int	count;
	int	i;
	int	help;

	i = 0;
	count = 1;
	help = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		if (s[i + 1] == c)
			while (s[i] == c)
				i++;
		if (s[i] != c)
			help++;
		i++;
	}
	if (help == 0)
		count = 0;
	return (count);
}

static char	*my_strtrim(char *s, char c)
{
	int		i_start;
	int		i_end;
	char	*clean_str;

	i_start = 0;
	i_end = ft_strlen(s);
	while (s[i_start] == c)
		i_start++;
	if (i_start >= i_end)
		return (ft_strdup(""));
	while (s[i_end - 1] == c)
		i_end--;
	clean_str = ft_substr(s, i_start, i_end - i_start);
	return (clean_str);
}

static	char	**main_f(char *s_copy, char c, int mas_count, int i)
{
	char	**res;
	int		k;

	k = 0;
	res = malloc(sizeof(char *) * (mas_count + 1));
	if (res == NULL)
		return (NULL);
	while ((i != mas_count) && (s_copy[k]))
	{
		while (s_copy[k] == c)
			k++;
		res[i] = ft_substr(s_copy, k, ft_extra_strlen(s_copy + k, c));
		if (res[i] == NULL)
		{
			while (i != -1)
				free(res[i--]);
			free(res);
			return (NULL);
		}
		while ((s_copy[k] != c) && (s_copy[k]))
			k++;
		i++;
	}
	res[mas_count] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	*s_copy;
	char	**res;
	int		mas_count;

	if (s == NULL)
		return (NULL);
	s_copy = my_strtrim((char *)s, c);
	if (s_copy == NULL)
		return (NULL);
	mas_count = mas_count_f(s_copy, c);
	res = main_f(s_copy, c, mas_count, 0);
	free(s_copy);
	return (res);
}
