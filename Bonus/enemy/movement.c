/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:13:21 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/04 16:48:18 by btvildia         ###   ########.fr       */
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

int	ft_enemy_movement_1(const int i, char **map, int x, int y)
{
	int	j;

	j = 0;
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'E' && i == 1)
		j = enemy_move(map, x, y, 1);
	else if (map[y + 1][x] != '1' && map[y + 1][x] != 'E' && i == 2)
		j = enemy_move(map, x, y, 2);
	else if (map[y][x - 1] != '1' && map[y][x - 1] != 'E' && i == 3)
		j = enemy_move(map, x, y, 3);
	else if (map[y][x + 1] != '1' && map[y][x + 1] != 'E' && i == 4)
		j = enemy_move(map, x, y, 4);
	return (j);
}

int	*ft_enemy_movement(const int *point, char **map, t_position posi)
{
	static int	*i;
	int			j;
	int			k;

	i = ft_malloc(sizeof(int) * posi.count);
	k = 0;
	j = 0;
	while (k < posi.count)
	{
		i[k] = ft_find_one(point[k], map, posi.x[k], posi.y[k]);
		if (point[k] == 1)
			j = ft_enemy_movement_1(point[k], map, posi.x[k], posi.y[k]);
		else if (point[k] == 2)
			j = ft_enemy_movement_1(point[k], map, posi.x[k], posi.y[k]);
		else if (point[k] == 3)
			j = ft_enemy_movement_1(point[k], map, posi.x[k], posi.y[k]);
		else if (point[k] == 4)
			j = ft_enemy_movement_1(point[k], map, posi.x[k], posi.y[k]);
		if (j == 1)
			i[0] = 15;
		k++;
	}
	free(posi.x);
	free(posi.y);
	return (i);
}
