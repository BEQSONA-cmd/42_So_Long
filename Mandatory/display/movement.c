/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:13:21 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/03 19:31:26 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
	draw_everything_2(params);
	return (0);
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

t_info	numbers_return(t_mlx params, int i)
{
	t_info	info;
	int		height;
	int		width;
	int		key;
	char	**map;

	map = params.map;
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
	info.x = player_position(map, 'P', 1);
	info.y = player_position(map, 'P', 2);
	return (info);
}

int	player_position(char **map, char c, int which)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == c)
			{
				if (which == 1)
					return (x);
				else if (which == 2)
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
