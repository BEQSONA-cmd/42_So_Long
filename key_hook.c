/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:55:50 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/18 20:11:23 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int			key_press;

void	key_check(int keycode, char **map, int x, int y)
{
	if (keycode == 119)
	{
		if (map[y - 1][x] != '1')
		{
			map[y][x] = '0';
			(y)--;
			map[y][x] = 'P';
		}
	}
	else if (keycode == 115)
	{
		if (map[y + 1][x] != '1')
		{
			map[y][x] = '0';
			(y)++;
			map[y][x] = 'P';
		}
	}
	else if (keycode == 97)
	{
		if (map[y][x - 1] != '1')
		{
			map[y][x] = '0';
			(x)--;
			map[y][x] = 'P';
		}
	}
	else if (keycode == 100)
	{
		if (map[y][x + 1] != '1')
		{
			map[y][x] = '0';
			(x)++;
			map[y][x] = 'P';
		}
	}
}

int	*player_position(char **map)
{
	int	i;
	int	y;
	int	x;
	int	*pos;

	i = 0;
	y = 0;
	x = 0;
	pos = (int *)malloc(2 * sizeof(int));
	while (map[y] != NULL && !i)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				pos[0] = x;
				pos[1] = y;
				break ;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

t_info	numbers_return(char **map)
{
	t_info	info;
	int		height;
	int		width;
	int		key;

	height = 0;
	while (map[height])
		height++;
	width = 0;
	while (map[0][width])
		width++;
	key = 100;
	info.height = height;
	info.width = width;
	info.key = key;
	info.x = player_position(map)[0];
	info.y = player_position(map)[1];
	return (info);
}

int	key_hook(int keycode, void **params)
{
	void	*mlx;
	void	*win;
	char	**map;
	t_info	info;

	mlx = params[0];
	win = params[1];
	map = params[2];
	info = numbers_return(map);
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx, win);
		ft_printf(GREEN "[PERFECT]\n" RESET);
		exit(0);
	}
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
		key_check(keycode, map, info.x, info.y);
	key_press = keycode;
	return (keycode);
}

t_textures	get_textures(void *mlx, int last_key)
{
	t_textures	textures;
	int			i;

	i = 64;
	last_key = key_press;
	textures.floor = mlx_xpm_file_to_image(mlx, "textures/Square.xpm", &i, &i);
	textures.wall = mlx_xpm_file_to_image(mlx, "textures/Wall.xpm", &i, &i);
	textures.left = mlx_xpm_file_to_image(mlx, "textures/Left.xpm", &i, &i);
	textures.right = mlx_xpm_file_to_image(mlx, "textures/Right.xpm", &i, &i);
	textures.up = mlx_xpm_file_to_image(mlx, "textures/Up.xpm", &i, &i);
	textures.down = mlx_xpm_file_to_image(mlx, "textures/Down.xpm", &i, &i);
	if (last_key == 97)
		textures.img = textures.left;
	else if (last_key == 100)
		textures.img = textures.right;
	else if (last_key == 119)
		textures.img = textures.up;
	else if (last_key == 115)
		textures.img = textures.down;
	else
		textures.img = textures.right;
	return (textures);
}
