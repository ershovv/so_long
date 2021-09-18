/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:54:16 by bshawn            #+#    #+#             */
/*   Updated: 2021/09/15 13:24:01 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*create_stats(char *steps, char *coins)
{
	char	*str1;
	char	*str2;
	char	*res;

	str1 = ft_strjoin("steps: ", steps);
	str2 = ft_strjoin("   robots:", coins);
	res = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	free(steps);
	free(coins);
	return (res);
}

void	print_map(t_game *game, int width, int hight, char **map)
{
	int		x;
	int		y;
	char	*stats;

	y = 0;
	while (y < hight)
	{
		x = 0;
		while (x < width)
		{
			put_image(game, map, x, y);
			x += game->obj_w;
		}
		y += game->obj_h;
	}
	stats = create_stats(ft_itoa(game->steps), ft_itoa(game->collect));
	mlx_string_put(game->mlx, game->win, 50, hight - 25,
		color(0, 0, 0, 0), stats);
	free(stats);
}
