/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:39:57 by bshawn            #+#    #+#             */
/*   Updated: 2021/09/14 19:42:51 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	sprites_init(t_sprites *sp, void *mlx)
{
	int	width;
	int	hight;

	sp->bg = mlx_xpm_file_to_image(mlx, "img/bg.xpm", &width, &hight);
	sp->wall = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &width, &hight);
	sp->coin = mlx_xpm_file_to_image(mlx, "img/coin.xpm", &width, &hight);
	sp->r_p = mlx_xpm_file_to_image(mlx, "img/pl/r_p.xpm", &width, &hight);
	sp->r_p1 = mlx_xpm_file_to_image(mlx, "img/pl/r_p1.xpm", &width, &hight);
	sp->l_p = mlx_xpm_file_to_image(mlx, "img/pl/l_p.xpm", &width, &hight);
	sp->l_p1 = mlx_xpm_file_to_image(mlx, "img/pl/l_p1.xpm", &width, &hight);
	sp->exit = mlx_xpm_file_to_image(mlx, "img/exit.xpm", &width, &hight);
	sp->enemy = mlx_xpm_file_to_image(mlx, "img/enemy.xpm", &width, &hight);
}

void	print_player(t_game *game, int x, int y)
{
	if (game->mr)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.bg, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.r_p, x, y);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.bg, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.l_p, x, y);
	}
}

void	put_image(t_game *game, char **map, int x, int y)
{
	int	xm;
	int	ym;

	ym = y / game->obj_h;
	xm = x / game->obj_w;
	if (map[ym][xm] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.bg, x, y);
	if (map[ym][xm] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.wall, x, y);
	if (map[ym][xm] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.bg, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.coin, x, y);
	}
	if (map[ym][xm] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.bg, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.exit, x, y);
	}
	if (map[ym][xm] == 'P')
		print_player(game, x, y);
	if (map[ym][xm] == 'X')
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprites.enemy, x, y);
}

int	color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
