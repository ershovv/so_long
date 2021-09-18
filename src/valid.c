/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 21:10:09 by bshawn            #+#    #+#             */
/*   Updated: 2021/09/15 19:11:09 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_out(t_map *mmap)
{
	if (mmap->C < 1 || mmap->E < 1)
	{
		printf("ERROR. minimum 1 coin and 1 exit\n");
		exit (1);
	}
	if (mmap->P != 1 )
	{
		printf("ERROR. Only 1 player.\n");
		exit (1);
	}
	if (mmap->trap < 1)
	{
		printf("ERROR. need traps\n");
		exit (1);
	}
	if (mmap->Walls)
	{
		printf("ERROR. bad walls.\n");
		exit (1);
	}
	if (mmap->any)
	{
		printf("ERROR. bad map.\n");
		exit (1);
	}
}

void	find_objects(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((int)ft_strlen(line) != map->width)
			map->Walls = 1;
		if (line[0] != '1')
			map->Walls = 1;
		if (line[ft_strlen(line) - 1] != '1')
			map->Walls = 1;
		if (line[i] == 'C')
			map->C++;
		if (line[i] == 'P')
			map->P++;
		if (line[i] == 'E')
			map->E++;
		if (line[i] == 'X')
			map->trap++;
		if (line[i] != 'E' && line[i] != 'P' && line[i] != 'C'
			&& line[i] != '1' && line[i] != '0' && line[i] != 'X')
			map->any += 1;
		i++;
	}
}

void	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_mas[0][i])
	{
		if (map->map_mas[0][i] != '1')
			map->Walls = 1;
		i++;
	}
	i = 0;
	while (map->map_mas[map->height - 1][i])
	{
		if (map->map_mas[map->height - 1][i] != '1')
			map->Walls = 1;
		i++;
	}
}

void	check_file(char **argv)
{
	int	b;
	int	fd;

	b = ft_strlen(argv[1]);
	if (b < 4)
		exit(1);
	if (argv[1][b - 4] != '.')
		exit(1);
	if (argv[1][b - 3] != 'b')
		exit(1);
	if (argv[1][b - 2] != 'e')
		exit(1);
	if (argv[1][b - 1] != 'r')
		exit(1);
	fd = open(argv[1], O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		printf("Your map is directory, fd = %d\n", fd);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	close(fd);
}

void	valid(int argc, char **argv, t_map *map)
{
	int	i;

	i = 0;
	if (argc != 2)
		exit(1);
	check_file(argv);
	map_init(map, argv);
	while (map->map_mas[i])
	{
		find_objects(map->map_mas[i], map);
		i++;
	}
	check_walls(map);
	error_out(map);
}
