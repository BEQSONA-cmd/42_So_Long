/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:55:50 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/22 19:25:19 by btvildia         ###   ########.fr       */
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

void	ft_movement(int keycode, char **map, int x, int y)
{
	if (keycode == 119 && map[y - 1][x] != '1' && map[y - 1][x] != 'E')
		ft_move(map, x, y, 1);
	else if (keycode == 115 && map[y + 1][x] != '1' && map[y + 1][x] != 'E')
		ft_move(map, x, y, 2);
	else if (keycode == 97 && map[y][x - 1] != '1' && map[y][x - 1] != 'E')
		ft_move(map, x, y, 3);
	else if (keycode == 100 && map[y][x + 1] != '1' && map[y][x + 1] != 'E')
		ft_move(map, x, y, 4);
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
	if (keycode == 65307)
		free_window(*params);
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
	{
		if (exit_check(keycode, map, info.x, info.y, c_count(map)) == 1)
			free_window(*params);
		check_c(keycode, map, info.x, info.y, c_count(map));
		ft_movement(keycode, map, info.x, info.y);
	}
	draw_map((t_mlx *)params);
	return (0);
}
