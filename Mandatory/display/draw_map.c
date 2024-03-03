/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:12:40 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/03 19:32:01 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_texture	get_texture(t_mlx *p)
{
	t_texture	texture;
	int			i;

	i = 64;
	texture.coin = mlx_xpm_file_to_image(p->mlx, "Mandatory/textures/coin.xpm",
			&i, &i);
	texture.exit = mlx_xpm_file_to_image(p->mlx, "Mandatory/textures/exit.xpm",
			&i, &i);
	texture.pac = mlx_xpm_file_to_image(p->mlx, "Mandatory/textures/pacman.xpm",
			&i, &i);
	return (texture);
}

void	draw_everything_2(t_mlx *p)
{
	t_texture	texture;

	texture = get_texture(p);
	draw_map_all(p, texture);
	mlx_destroy_image(p->mlx, texture.coin);
	mlx_destroy_image(p->mlx, texture.exit);
	mlx_destroy_image(p->mlx, texture.pac);
}

int	draw_map_all(t_mlx *p, t_texture t)
{
	int		x;
	int		y;
	t_info	info;

	info = numbers_return(*p, 0);
	y = 0;
	draw_wall_floor(p, info.height, info.width, y);
	while (y < info.height)
	{
		x = 0;
		while (x < info.width)
		{
			if (p->map[y][x] == 'P')
				mlx_put_image_to_window(p->mlx, p->win, t.pac, x * TS, y * TS);
			if (p->map[y][x] == 'C')
				mlx_put_image_to_window(p->mlx, p->win, t.coin, x * TS, y * TS);
			if (p->map[y][x] == 'E')
				mlx_put_image_to_window(p->mlx, p->win, t.exit, x * TS, y * TS);
			x++;
		}
		y++;
	}
	return (0);
}

int	draw_win(t_mlx *p)
{
	void	*win;
	int		i;
	int		j;
	int		x;
	int		y;

	y = 0;
	while (p->map[y])
	{
		x = 0;
		while (p->map[y][x])
			x++;
		y++;
	}
	if (x < 14)
		x = 14;
	if (y < 4)
		y = 4;
	i = 489;
	j = 258;
	win = mlx_xpm_file_to_image(p->mlx, "Mandatory/textures/win.xpm", &i, &j);
	mlx_put_image_to_window(p->mlx, p->win, win, (x * TS) / 2 - i / 2, (y * TS)
		/ 2 - j / 2);
	mlx_destroy_image(p->mlx, win);
	return (0);
}

void	draw_wall_floor(t_mlx *p, int height, int width, int y)
{
	void	*floor;
	void	*wall;
	int		x;
	char	**map;

	floor = mlx_xpm_file_to_image(p->mlx, "Mandatory/textures/Square.xpm", &y,
			&y);
	wall = mlx_xpm_file_to_image(p->mlx, "Mandatory/textures/Wall.xpm", &y, &y);
	y = 0;
	map = p->map;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(p->mlx, p->win, floor, x * TS, y * TS);
			else if (map[y][x] == '0')
				mlx_put_image_to_window(p->mlx, p->win, wall, x * TS, y * TS);
			x++;
		}
		y++;
	}
	mlx_destroy_image(p->mlx, floor);
	mlx_destroy_image(p->mlx, wall);
}
