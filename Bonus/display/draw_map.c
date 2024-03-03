/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:12:40 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/02 23:50:07 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	draw_everything(t_mlx *p)
{
	static int	previous_c = -1;
	t_info		info;
	char		**map;
	int			j;

	j = check_level(p->level);
	map = p->map;
	info = numbers_return(*p, 0);
	if (previous_c == -1)
		previous_c = c_count(map);
	draw_map(p, info.height, info.width, map);
	draw_coin_count(p, from_zero(map, &previous_c), info.width, info.height);
	draw_moves(p, info.width, info.height);
	draw_enemys(p, map, j);
	return (0);
}

int	draw_map(t_mlx *p, int height, int width, char **map)
{
	int	x;
	int	y;

	y = 0;
	draw_wall_floor(p, height, width, y);
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == 'P')
				draw_pacman(p, x, y, 0);
			if (map[y][x] == 'C')
				draw_coin(p, x, y, 0);
			if (map[y][x] == 'E')
				draw_exit(p, x, y, 0);
			if (map[y][x] == 'S')
				draw_enemy(p, x, y, 0);
			x++;
		}
		y++;
	}
	return (0);
}

void	draw_pacman(t_mlx *params, int x, int y, int frame)
{
	static t_animations		player;
	char					*c;
	int						i;
	static struct timeval	lst;

	i = 64;
	destroy_frame(params, &player, 10);
	while (frame < 10)
	{
		c = load_pacman_texture(frame, params->keycode);
		player.pacman[frame] = mlx_xpm_file_to_image(params->mlx, c, &i, &i);
		free(c);
		frame++;
	}
	mlx_put_image_to_window(params->mlx, params->win,
		player.pacman[player.frame], x * TS, y * TS);
	update_frame(&player, &lst, 30000, 10);
}

void	draw_exit(t_mlx *p, int x, int y, int frame)
{
	static t_animations		ex;
	char					*c;
	int						i;
	static struct timeval	lst;

	i = 64;
	destroy_frame_2(p, &ex, 1);
	while (frame < 12)
	{
		c = combine("Bonus/textures/exit/", frame + 1, ".xpm");
		ex.exit[frame] = mlx_xpm_file_to_image(p->mlx, c, &i, &i);
		free(c);
		frame++;
	}
	mlx_put_image_to_window(p->mlx, p->win, ex.exit[ex.frame], x * TS, y * TS);
	update_frame(&ex, &lst, 30000, 12);
}

void	draw_coin(t_mlx *p, int x, int y, int frame)
{
	static t_animations		co;
	char					*c;
	int						i;
	static struct timeval	lst;

	i = 64;
	destroy_frame_2(p, &co, 0);
	while (frame < 12)
	{
		c = combine("Bonus/textures/coin/", frame + 1, ".xpm");
		co.coin[frame] = mlx_xpm_file_to_image(p->mlx, c, &i, &i);
		free(c);
		frame++;
	}
	mlx_put_image_to_window(p->mlx, p->win, co.coin[co.frame], x * TS, y * TS);
	update_frame(&co, &lst, 50000, 12);
}
