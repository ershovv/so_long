/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:26:34 by bshawn            #+#    #+#             */
/*   Updated: 2021/09/14 19:14:35 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_pos(t_game *game, char **map)
{
	int	i;
	int	k;

	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == 'P')
			{
				game->map.p_pos_x = k;
				game->map.p_pos_y = i;
			}
			k++;
		}
		i++;
	}
}

void	game_init(t_game *game, int width, int hight)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, width * game->map.width,
			hight * game->map.height, "so_long");
	game->obj_w = width;
	game->obj_h = hight;
	player_pos(game, game->map.map_mas);
	game->steps = 0;
	game->collect = 0;
	game->mr = 1;
	game->anim = 0;
	sprites_init(&game->sprites, game->mlx);
	print_map(game, width * game->map.width,
		hight * game->map.height, game->map.map_mas);
}
