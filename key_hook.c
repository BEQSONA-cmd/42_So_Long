/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:55:50 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/26 22:01:12 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_window(t_mlx params)
{
	mlx_destroy_window(params.mlx, params.win);
	ft_printf(GREEN "PERFECT\n" RESET);
	exit(0);
}

t_info	numbers_return(t_mlx params, int i)
{
	t_info	info;
	int		height;
	int		width;
	int		key;
	char	**map;

	map = params.map;
	info.floor = mlx_xpm_file_to_image(params.mlx, "textures/Square.xpm", &i,
			&i);
	info.wall = mlx_xpm_file_to_image(params.mlx, "textures/Wall.xpm", &i, &i);
	i = 64;
	height = 0;
	while (map[height])
		height++;
	width = 0;
	while (map[0][width])
		width++;
	key = D;
	info.height = height;
	info.width = width;
	info.x = player_position(map)[0];
	info.y = player_position(map)[1];
	info.enemy_x = enemy_position(map)[0];
	info.enemy_y = enemy_position(map)[1];
	return (info);
}

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
	if (keycode == W && map[y - 1][x] != '1' && map[y - 1][x] != 'E')
	{
		ft_move(map, x, y, 1);
		return (1);
	}
	else if (keycode == S && map[y + 1][x] != '1' && map[y + 1][x] != 'E')
	{
		ft_move(map, x, y, 2);
		return (1);
	}
	else if (keycode == A && map[y][x - 1] != '1' && map[y][x - 1] != 'E')
	{
		ft_move(map, x, y, 3);
		return (1);
	}
	else if (keycode == D && map[y][x + 1] != '1' && map[y][x + 1] != 'E')
	{
		ft_move(map, x, y, 4);
		return (1);
	}
	return (0);
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
		if (exit_check(keycode, map, info.x, info.y) == 1)
			mlx_loop_hook(params->mlx, draw_win, (void *)params);
		if (ft_movement(keycode, map, info.x, info.y) == 1)
			params->moves++;
	}
	return (0);
}
