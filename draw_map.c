/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:12:40 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/26 19:59:47 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_win(t_mlx *p)
{
	void	*loose;
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
	i = 489;
	j = 258;
	loose = mlx_xpm_file_to_image(p->mlx, "./textures/you_win.xpm", &i, &j);
	mlx_put_image_to_window(p->mlx, p->win, loose, (x * TS) / 2 - i / 2, (y
			* TS) / 2 - j / 2);
	return (0);
}

int	draw_loose(t_mlx *p)
{
	void	*loose;
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
	i = 489;
	j = 258;
	loose = mlx_xpm_file_to_image(p->mlx, "./textures/you_loose.xpm", &i, &j);
	mlx_put_image_to_window(p->mlx, p->win, loose, (x * TS) / 2 - i / 2, (y
			* TS) / 2 - j / 2);
	return (0);
}

void	draw_pacman(t_mlx *params, int x, int y, int frame)
{
	static t_animations		exit;
	char					*c;
	int						i;
	static struct timeval	lst;
	struct timeval			now;

	i = 64;
	while (frame < 10)
	{
		c = load_pacman_texture(frame, params->keycode);
		exit.exit[frame] = mlx_xpm_file_to_image(params->mlx, c, &i, &i);
		frame++;
	}
	mlx_put_image_to_window(params->mlx, params->win, exit.exit[exit.frame], x
		* TS, y * TS);
	gettimeofday(&now, NULL);
	if (now.tv_sec > lst.tv_sec || (now.tv_sec == lst.tv_sec && now.tv_usec
			- lst.tv_usec > 30000))
	{
		exit.frame = (exit.frame + 1) % 10;
		lst = now;
	}
}

void	draw_exit(t_mlx *params, int x, int y, int frame)
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
			exit.exit[frame] = mlx_xpm_file_to_image(params->mlx, c, &i, &i);
			frame++;
		}
	}
	mlx_put_image_to_window(params->mlx, params->win, exit.exit[exit.frame], x
		* TS, y * TS);
	gettimeofday(&now, NULL);
	if (now.tv_sec > lst.tv_sec || (now.tv_sec == lst.tv_sec && now.tv_usec
			- lst.tv_usec > 50000))
	{
		exit.frame = (exit.frame + 1) % 12;
		lst = now;
	}
}

void	draw_coin(t_mlx *params, int x, int y, int frame)
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
			coin.coin[frame] = mlx_xpm_file_to_image(params->mlx, c, &i, &i);
			frame++;
		}
	}
	mlx_put_image_to_window(params->mlx, params->win, coin.coin[coin.frame], x
		* TS, y * TS);
	gettimeofday(&now, NULL);
	if (now.tv_sec > lst.tv_sec || (now.tv_sec == lst.tv_sec && now.tv_usec
			- lst.tv_usec > 50000))
	{
		coin.frame = (coin.frame + 1) % 12;
		lst = now;
	}
}
