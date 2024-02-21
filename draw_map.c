/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 00:27:58 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/19 15:53:10 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_exit(void *mlx, void *win, int x, int y, int frame)
{
	static t_animations		exit;
	char					filename[64];
	int						i;
	static struct timeval	lst;
	struct timeval			now;

	i = 64;
	if (exit.frame == 0)
	{
		while (frame < 12)
		{
			sprintf(filename, "textures/exit/%d.xpm", frame + 1);
			exit.exit[frame] = mlx_xpm_file_to_image(mlx, filename, &i, &i);
			frame++;
		}
	}
	mlx_put_image_to_window(mlx, win, exit.exit[exit.frame], x * TS, y * TS);
	gettimeofday(&now, NULL);
	if (now.tv_sec > lst.tv_sec || (now.tv_sec == lst.tv_sec && now.tv_usec
			- lst.tv_usec > 50000))
	{
		exit.frame = (exit.frame + 1) % 12;
		lst = now;
	}
}

void	draw_coin(void *mlx, void *win, int x, int y, int frame)
{
	static t_animations		coin;
	char					filename[64];
	int						i;
	static struct timeval	lst;
	struct timeval			now;

	i = 64;
	if (coin.frame == 0)
	{
		while (frame < 12)
		{
			sprintf(filename, "textures/coin/%d.xpm", frame + 1);
			coin.coin[frame] = mlx_xpm_file_to_image(mlx, filename, &i, &i);
			frame++;
		}
	}
	mlx_put_image_to_window(mlx, win, coin.coin[coin.frame], x * TS, y * TS);
	gettimeofday(&now, NULL);
	if (now.tv_sec > lst.tv_sec || (now.tv_sec == lst.tv_sec && now.tv_usec
			- lst.tv_usec > 50000))
	{
		coin.frame = (coin.frame + 1) % 12;
		lst = now;
	}
}

void	draw_map(void *mlx, void *win, char **map, int last_key)
{
	unsigned long	y;
	unsigned long	x;
	t_textures		text;
	t_info			info;

	info = numbers_return(map);
	text = get_textures(mlx, last_key);
	y = 0;
	while (y < info.height)
	{
		x = 0;
		while (x < info.width)
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx, win, text.floor, x * TS, y * TS);
			else if (map[y][x] == '0')
				mlx_put_image_to_window(mlx, win, text.wall, x * TS, y * TS);
			else if (map[y][x] == 'P')
				mlx_put_image_to_window(mlx, win, text.img, x * TS, y * TS);
			else if (map[y][x] == 'C')
				draw_coin(mlx, win, x, y, 0);
			else if (map[y][x] == 'E')
				draw_exit(mlx, win, x, y, 0);
			x++;
		}
		y++;
	}
}

int	loop_hook(void **params)
{
	void	*mlx;
	void	*win;
	char	**map;
	int		key;

	key = 0;
	mlx = params[0];
	win = params[1];
	map = params[2];
	draw_map(mlx, win, map, key);
	return (0);
}
