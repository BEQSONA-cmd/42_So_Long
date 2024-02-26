/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:55:50 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/26 14:45:50 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(char **map, int x, int y, int num)
{
	if (num == 1)
	{
		map[y][x] = '0';
		y--;
		map[y][x] = 'P';
	}
	else if (num == 2)
	{
		map[y][x] = '0';
		y++;
		map[y][x] = 'P';
	}
	else if (num == 3)
	{
		map[y][x] = '0';
		x--;
		map[y][x] = 'P';
	}
	else if (num == 4)
	{
		map[y][x] = '0';
		x++;
		map[y][x] = 'P';
	}
}

int	ft_movement(int keycode, char **map, int x, int y)
{
	int	i;

	i = 0;
	if (keycode == W && map[y - 1][x] != '1' && map[y - 1][x] != 'E')
	{
		if (map[y - 1][x] == 'S')
			i = 1;
		ft_move(map, x, y, 1);
	}
	else if (keycode == S && map[y + 1][x] != '1' && map[y + 1][x] != 'E')
	{
		if (map[y + 1][x] == 'S')
			i = 1;
		ft_move(map, x, y, 2);
	}
	else if (keycode == A && map[y][x - 1] != '1' && map[y][x - 1] != 'E')
	{
		if (map[y][x - 1] == 'S')
			i = 1;
		ft_move(map, x, y, 3);
	}
	else if (keycode == D && map[y][x + 1] != '1' && map[y][x + 1] != 'E')
	{
		if (map[y][x + 1] == 'S')
			i = 1;
		ft_move(map, x, y, 4);
	}
	return (i);
}

int	key_hook(int keycode, t_mlx *params)
{
	void	*mlx;
	void	*win;
	char	**map;
	
	t_info	info;

	info = numbers_return(*params, 0);
	mlx = params->mlx;
	win = params->win;
	map = params->map;
	params->keycode = keycode;
	if (keycode == ESC)
		free_window(*params);
	if (keycode == W || keycode == S || keycode == A || keycode == D)
	{
		if (exit_check(keycode, map, info.x, info.y, c_count(map)) == 1)
			mlx_loop_hook(params->mlx, draw_win, (void *)params);
		ft_movement(keycode, map, info.x, info.y);
	}
	return (0);
}
