/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 10:14:21 by bshawn            #+#    #+#             */
/*   Updated: 2021/09/14 18:37:59 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	m_right(t_game *game)
{
	int		x;
	int		y;
	char	next;

	x = game->map.p_pos_x;
	y = game->map.p_pos_y;
	next = game->map.map_mas[y][x + 1];
	if (next != '1' && next != 'E' && next != 'X')
	{
		if (next == 'C')
			game->collect += 1;
		game->map.map_mas[y][x] = '0';
		game->map.map_mas[y][x + 1] = 'P';
		game->map.p_pos_x = x + 1;
		game->mr = 1;
		return (1);
	}
	if (next == 'E' && game->collect == game->map.C)
		exit_game();
	if (next == 'X')
		exit_game();
	return (0);
}

int	m_left(t_game *game)
{
	int		x;
	int		y;
	char	next;

	x = game->map.p_pos_x;
	y = game->map.p_pos_y;
	next = game->map.map_mas[y][x - 1];
	if (next != '1' && next != 'E' && next != 'X')
	{
		if (next == 'C')
			game->collect += 1;
		game->map.map_mas[y][x] = '0';
		game->map.map_mas[y][x - 1] = 'P';
		game->map.p_pos_x = x - 1;
		game->mr = 0;
		return (1);
	}
	if (next == 'E' && game->collect == game->map.C)
		exit_game();
	if (next == 'X')
		exit_game();
	return (0);
}

int	m_up(t_game *game)
{
	int		x;
	int		y;
	char	next;

	x = game->map.p_pos_x;
	y = game->map.p_pos_y;
	next = game->map.map_mas[y - 1][x];
	if (next != '1' && next != 'E' && next != 'X')
	{
		if (next == 'C')
			game->collect += 1;
		game->map.map_mas[y][x] = '0';
		game->map.map_mas[y - 1][x] = 'P';
		game->map.p_pos_y = y - 1;
		return (1);
	}
	if (next == 'E' && game->collect == game->map.C)
		exit_game();
	if (next == 'X')
		exit_game();
	return (0);
}

int	m_down(t_game *game)
{
	int		x;
	int		y;
	char	next;

	x = game->map.p_pos_x;
	y = game->map.p_pos_y;
	next = game->map.map_mas[y + 1][x];
	if (next != '1' && next != 'E' && next != 'X')
	{
		if (next == 'C')
			game->collect += 1;
		game->map.map_mas[y][x] = '0';
		game->map.map_mas[y + 1][x] = 'P';
		game->map.p_pos_y = y + 1;
		return (1);
	}
	if (next == 'E' && game->collect == game->map.C)
		exit_game();
	if (next == 'X')
		exit_game();
	return (0);
}

void	move(int code, t_game *game)
{
	if (code == 53)
		exit_game();
	if (code == 2)
	{
		if (m_right(game))
			game->steps++;
	}
	if (code == 0)
	{
		if (m_left(game))
			game->steps++;
	}
	if (code == 13)
	{
		if (m_up(game))
			game->steps++;
	}
	if (code == 1)
	{
		if (m_down(game))
			game->steps++;
	}
}
