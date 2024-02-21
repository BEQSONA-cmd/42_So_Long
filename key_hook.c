/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:55:50 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/21 23:20:10 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		g_keypress;

void	ft_movement(int keycode, char **map, int x, int y)
{
	if (keycode == 119 && map[y - 1][x] != '1' && map[y - 1][x] != 'E')
	{
		map[y][x] = '0';
		y--;
		map[y][x] = 'P';
	}
	else if (keycode == 115 && map[y + 1][x] != '1' && map[y + 1][x] != 'E')
	{
		map[y][x] = '0';
		y++;
		map[y][x] = 'P';
	}
	else if (keycode == 97 && map[y][x - 1] != '1' && map[y][x - 1] != 'E')
	{
		map[y][x] = '0';
		x--;
		map[y][x] = 'P';
	}
	else if (keycode == 100 && map[y][x + 1] != '1' && map[y][x + 1] != 'E')
	{
		map[y][x] = '0';
		x++;
		map[y][x] = 'P';
	}
}

int	key_hook(int keycode, void **params)
{
	void	*mlx;
	void	*win;
	char	**map;
	t_info	info;

	g_keypress = keycode;
	info = numbers_return(params, 0);
	mlx = params[0];
	win = params[1];
	map = params[2];
	if (keycode == 65307)
		free_window(params);
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
	{
		if (exit_check(keycode, map, info.x, info.y, c_count(map)) == 1)
			free_window(params);
		check_c(keycode, map, info.x, info.y, c_count(map));
		ft_movement(keycode, map, info.x, info.y);
	}
	return (0);
}

char	*load_pacman_texture(int frame)
{
	char	*c;

	if (g_keypress == 119)
		c = combine("textures/pacman/up/up", frame + 1, ".xpm");
	else if (g_keypress == 115)
		c = combine("textures/pacman/down/down", frame + 1, ".xpm");
	else if (g_keypress == 97)
		c = combine("textures/pacman/left/left", frame + 1, ".xpm");
	else if (g_keypress == 100)
		c = combine("textures/pacman/right/right", frame + 1, ".xpm");
	else
		c = combine("textures/pacman/right/right", frame + 1, ".xpm");
	return (c);
}
