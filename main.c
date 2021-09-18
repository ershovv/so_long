/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:21:18 by bshawn            #+#    #+#             */
/*   Updated: 2021/09/15 12:36:49 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

#define WIDTH 100
#define HEIGHT 100

int	exit_game(void)
{
	exit(0);
}

int	key_hook(int code, t_game *game)
{
	move(code, game);
	mlx_clear_window(game->mlx, game->win);
	print_map(game, WIDTH * game->map.width,
		HEIGHT * game->map.height, game->map.map_mas);
	return (code);
}

int	main(int argc, char **argv)
{
	t_game	game;

	valid(argc, argv, &game.map);
	game_init(&game, WIDTH, HEIGHT);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_hook(game.win, 2, 0, key_hook, &game);
	mlx_loop_hook(game.mlx, animation, &game);
	mlx_loop(game.mlx);
}
