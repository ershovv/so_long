/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:30:47 by bshawn            #+#    #+#             */
/*   Updated: 2021/09/14 21:23:44 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFFER_SIZE 2

char	*new_string(size_t len)
{
	char		*str;
	size_t		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
	str[len] = '\0';
	return (str);
}

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*okey(char **line, char *buf)
{
	char		*search;

	search = NULL;
	if (ft_strlen(buf))
	{
		search = ft_strchr(buf, '\n');
		if (search)
		{
			*search = '\0';
			*line = ft_strdup(buf);
			ft_strcpy(buf, ++search);
		}
		else
			*line = ft_strdup(buf);
	}
	else
		*line = new_string(1);
	return (search);
}

static void	*strdup_mod(char *buf, char *search)
{
	size_t	i;

	i = 0;
	while (i != ft_strlen(search))
	{
		buf[i] = search[i];
		i++;
	}
	buf[i] = '\0';
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	int				bytes;
	char			*search;

	if ((fd < 0) || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (-1);
	bytes = 1;
	search = okey(line, buf);
	while ((bytes) && (!search))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		buf[bytes] = '\0';
		search = ft_strchr(buf, '\n');
		if (search)
		{
			*search = '\0';
			*line = ft_strjoin_m(*line, buf);
			strdup_mod(buf, ++search);
		}
		else
			*line = ft_strjoin_m(*line, buf);
	}
	if (bytes)
		return (1);
	return (0);
}
