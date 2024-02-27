/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:12:40 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/27 23:22:31 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_map(t_mlx *p, char **map, t_info i, int y)
{
	int	x;

	y = 0;
	while (y < i.height)
	{
		x = 0;
		while (x < i.width)
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(p->mlx, p->win, i.floor, x * TS, y
					* TS);
			else if (map[y][x] == '0')
				mlx_put_image_to_window(p->mlx, p->win, i.wall, x * TS, y * TS);
			else if (map[y][x] == 'P')
				draw_pacman(p, x, y, 0);
			else if (map[y][x] == 'C')
				draw_coin(p, x, y, 0);
			else if (map[y][x] == 'E')
				draw_exit(p, x, y, 0);
			else if (map[y][x] == 'S')
				draw_enemy(p, x, y, 0);
			x++;
		}
		y++;
	}
}

int	draw_everything(t_mlx *p)
{
	t_info		info;
	char		**map;
	static int	previous_c = -1;
	t_position	posi;
	const int	*i;

	map = p->map;
	info = numbers_return(*p, 0);
	if (previous_c == -1)
		previous_c = c_count(map);
	draw_map(p, p->map, info, 0);
	draw_coin_count(p, from_zero(map, &previous_c), info.width, info.height);
	draw_moves(p, info.width, info.height);
	p->frame++;
	if (p->frame >= 30)
	{
		posi = enemys_positioon(map);
		i = point_return(map, p->temp_j);
		p->temp_j = ft_enemy_movement(i, map, posi);
		p->key = i[0];
		p->frame = 0;
		if (p->temp_j[0] == 15)
			mlx_loop_hook(p->mlx, draw_loose, (void *)p);
	}
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
		free(c);
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

void	draw_exit(t_mlx *p, int x, int y, int frame)
{
	static t_animations		ex;
	char					*c;
	int						i;
	static struct timeval	lst;
	struct timeval			now;

	i = 64;
	if (ex.frame == 0)
	{
		while (frame < 12)
		{
			c = combine("textures/exit/", frame + 1, ".xpm");
			ex.exit[frame] = mlx_xpm_file_to_image(p->mlx, c, &i, &i);
			free(c);
			frame++;
		}
	}
	mlx_put_image_to_window(p->mlx, p->win, ex.exit[ex.frame], x * TS, y * TS);
	gettimeofday(&now, NULL);
	if (now.tv_sec > lst.tv_sec || (now.tv_sec == lst.tv_sec && now.tv_usec
			- lst.tv_usec > 50000))
	{
		ex.frame = (ex.frame + 1) % 12;
		lst = now;
	}
}

void	draw_coin(t_mlx *p, int x, int y, int frame)
{
	static t_animations		co;
	char					*c;
	int						i;
	static struct timeval	lst;
	struct timeval			now;

	i = 64;
	if (co.frame == 0)
	{
		while (frame < 12)
		{
			c = combine("textures/coin/", frame + 1, ".xpm");
			co.coin[frame] = mlx_xpm_file_to_image(p->mlx, c, &i, &i);
			free(c);
			frame++;
		}
	}
	mlx_put_image_to_window(p->mlx, p->win, co.coin[co.frame], x * TS, y * TS);
	gettimeofday(&now, NULL);
	if (now.tv_sec > lst.tv_sec || (now.tv_sec == lst.tv_sec && now.tv_usec
			- lst.tv_usec > 50000))
	{
		co.frame = (co.frame + 1) % 12;
		lst = now;
	}
}
