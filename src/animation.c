/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:18:22 by bshawn            #+#    #+#             */
/*   Updated: 2021/09/14 19:58:42 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	right(t_game *game, int x, int y)
{
	if (game->anim)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.bg, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.r_p, x, y);
		game->anim = 0;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.bg, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.r_p1, x, y);
		game->anim = 1;
	}
}

void	left(t_game *game, int x, int y)
{
	if (game->anim)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.bg, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.l_p, x, y);
		game->anim = 0;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.bg, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.l_p1, x, y);
		game->anim = 1;
	}
}

void	put_player(t_game *game, int x, int y)
{
	if (game->mr)
	{
		right(game, x, y);
	}
	else
	{
		left(game, x, y);
	}
}

int	animation(t_game *game)
{
	int	x;
	int	y;
	int	time;

	time = 0;
	x = game->map.p_pos_x * game->obj_w;
	y = game->map.p_pos_y * game->obj_h;
	while (time != 59999999)
		time++;
	put_player(game, x, y);
	return (1);
}
