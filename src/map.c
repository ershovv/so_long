/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 12:41:00 by bshawn            #+#    #+#             */
/*   Updated: 2021/09/15 16:38:16 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_weight(char **argv)
{
	char	*line;
	int		i;
	int		fd;
	int		res;

	res = 0;
	fd = open(argv[1], O_RDONLY);
	i = get_next_line(fd, &line);
	if (fd)
		close (fd);
	if (line)
	{
		res = (int)ft_strlen(line);
		free(line);
	}
	if ((!res))
		exit(1);
	if (res > 30)
	{
		printf("big map.");
		exit(1);
	}
	return (res);
}

int	map_height(char **argv)
{
	char	*line;
	int		i;
	int		fd;
	int		len;

	len = 0;
	fd = open(argv[1], O_RDONLY);
	i = get_next_line(fd, &line);
	if (line)
	{
		len = 1;
		free(line);
	}
	while (i)
	{	
		len++;
		i = get_next_line(fd, &line);
		free(line);
	}
	if (fd)
		close(fd);
	if ((!len) || (len > 30))
		exit(1);
	return (len);
}

void	save_map(t_map *map, char **argv)
{
	int		fd;
	int		i;
	int		s;
	char	*line;

	s = 0;
	fd = open(argv[1], O_RDONLY);
	i = get_next_line(fd, &line);
	map->map_mas = malloc(sizeof(char *) * map->height + 1);
	if (!map->map_mas)
		exit(1);
	map->map_mas[map->height] = NULL;
	map->map_mas[s] = ft_strdup(line);
	if (!map->map_mas[s])
		exit(1);
	free(line);
	while (i)
	{
		s++;
		i = get_next_line(fd, &line);
		map->map_mas[s] = ft_strdup(line);
		if (!map->map_mas[s])
			exit(1);
		free(line);
	}
}

void	map_init(t_map *map, char **argv)
{
	map->width = map_weight(argv);
	map->height = map_height(argv);
	save_map(map, argv);
	map->C = 0;
	map->P = 0;
	map->E = 0;
	map->trap = 0;
	map->any = 0;
	map->Walls = 0;
}
