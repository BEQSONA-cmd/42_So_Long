/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 00:27:58 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/21 23:39:58 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_pacman(void **params, int x, int y, int frame)
{
	static t_animations		exit;
	char					*c;
	int						i;
	static struct timeval	lst;
	struct timeval			now;

	i = 64;
	while (frame < 10)
	{
		c = load_pacman_texture(frame);
		exit.exit[frame] = mlx_xpm_file_to_image(params[0], c, &i, &i);
		frame++;
	}
	mlx_put_image_to_window(params[0], params[1], exit.exit[exit.frame], x * TS,
		y * TS);
	gettimeofday(&now, NULL);
	if (now.tv_sec > lst.tv_sec || (now.tv_sec == lst.tv_sec && now.tv_usec
			- lst.tv_usec > 30000))
	{
		exit.frame = (exit.frame + 1) % 10;
		lst = now;
	}
}

void	draw_exit(void **params, int x, int y, int frame)
{
	static t_animations		exit;
	char					*c;
	int						i;
	static struct timeval	lst;
	struct timeval			now;

	i = 64;
	if (exit.frame == 0)
	{
		while (frame < 12)
		{
			c = combine("textures/exit/", frame + 1, ".xpm");
			exit.exit[frame] = mlx_xpm_file_to_image(params[0], c, &i, &i);
			frame++;
		}
	}
	mlx_put_image_to_window(params[0], params[1], exit.exit[exit.frame], x * TS,
		y * TS);
	gettimeofday(&now, NULL);
	if (now.tv_sec > lst.tv_sec || (now.tv_sec == lst.tv_sec && now.tv_usec
			- lst.tv_usec > 50000))
	{
		exit.frame = (exit.frame + 1) % 12;
		lst = now;
	}
}

void	draw_coin(void **params, int x, int y, int frame)
{
	static t_animations		coin;
	char					*c;
	int						i;
	static struct timeval	lst;
	struct timeval			now;

	i = 64;
	if (coin.frame == 0)
	{
		while (frame < 12)
		{
			c = combine("textures/coin/", frame + 1, ".xpm");
			coin.coin[frame] = mlx_xpm_file_to_image(params[0], c, &i, &i);
			frame++;
		}
	}
	mlx_put_image_to_window(params[0], params[1], coin.coin[coin.frame], x * TS,
		y * TS);
	gettimeofday(&now, NULL);
	if (now.tv_sec > lst.tv_sec || (now.tv_sec == lst.tv_sec && now.tv_usec
			- lst.tv_usec > 50000))
	{
		coin.frame = (coin.frame + 1) % 12;
		lst = now;
	}
}

int	draw_map(void **p)
{
	int		y;
	int		x;
	t_info	info;
	char	**map;

	map = p[2];
	info = numbers_return(p, 0);
	y = 0;
	while (y < info.height)
	{
		x = 0;
		while (x < info.width)
		{
			mlx_string_put(p[0], p[1], info.width * 59, 64 * (info.height
					+ 0.5), WHITE, "Your text here");
			if (map[y][x] == '1')
				mlx_put_image_to_window(p[0], p[1], info.floor, x * TS, y * TS);
			else if (map[y][x] == '0')
				mlx_put_image_to_window(p[0], p[1], info.wall, x * TS, y * TS);
			else if (map[y][x] == 'P')
				draw_pacman(p, x, y, 0);
			else if (map[y][x] == 'C')
				draw_coin(p, x, y, 0);
			else if (map[y][x] == 'E')
				draw_exit(p, x, y, 0);
			x++;
		}
		y++;
	}
	return (0);
}
