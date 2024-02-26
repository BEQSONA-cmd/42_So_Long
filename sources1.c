/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:08:39 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/26 22:20:03 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	posi = enemys_positioon(map);
	info = numbers_return(*p, 0);
	if (previous_c == -1)
		previous_c = c_count(map);
	draw_map(p, p->map, info, 0);
	draw_coin_count(p, from_zero(map, &previous_c), info.width, info.height);
	draw_moves(p, info.width, info.height);
	p->frame++;
	if (p->frame >= 30)
	{
		i = point_return(map, p->temp_j);
		p->temp_j = ft_enemy_movement(i, map, posi.x, posi.y);
		p->key = i[0];
		p->frame = 0;
		if (p->temp_j[0] == 15)
			mlx_loop_hook(p->mlx, draw_loose, (void *)p);
	}
	return (0);
}
