/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:32:37 by bshawn            #+#    #+#             */
/*   Updated: 2021/09/15 16:35:54 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./minilibx/mlx.h"

typedef struct s_sprites {
	void	*bg;
	void	*wall;
	void	*r_p;
	void	*r_p1;
	void	*l_p;
	void	*l_p1;
	void	*coin;
	void	*exit;
	void	*enemy;
}				t_sprites;

typedef struct s_map {
	int		C;
	int		P;
	int		E;
	int		trap;
	int		Walls;
	int		any;
	int		width;
	int		height;
	char	**map_mas;
	int		p_pos_y;
	int		p_pos_x;
}				t_map;

typedef struct s_game {
	void		*mlx;
	void		*win;

	t_map		map;
	t_sprites	sprites;

	int			obj_w;
	int			obj_h;

	int			steps;
	int			collect;

	int			mr;
	int			anim;
}			t_game;

int		exit_game(void);
int		animation(t_game *game);
int		color(int t, int r, int g, int b);
void	valid(int argc, char **argv, t_map *map);
void	error_out(t_map *mmap);
void	map_init(t_map *map, char **argv);
void	game_init(t_game *game, int weidth, int height);
void	move(int code, t_game *game);
void	sprites_init(t_sprites *sprites, void *mlxs);
void	print_map(t_game *game, int width, int height, char **map);
void	put_image(t_game *game, char **map, int x, int y);
#endif