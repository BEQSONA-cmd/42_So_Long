/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:17:36 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/02 23:50:57 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	draw_enemy(t_mlx *params, int x, int y, int frame)
{
	static t_animations		gost;
	static struct timeval	lst;
	static int				j;
	int						i;
	char					*c;

	destroy_frame(params, &gost, 8);
	if (params->key == 3 || params->key == 4)
		j = params->key;
	while (frame < 8)
	{
		c = load_enemy_texture(frame, j);
		gost.gost[frame] = mlx_xpm_file_to_image(params->mlx, c, &i, &i);
		free(c);
		frame++;
	}
	mlx_put_image_to_window(params->mlx, params->win, gost.gost[gost.frame], x
		* TS, y * TS);
	update_frame(&gost, &lst, 70000, 8);
}

void	draw_enemys(t_mlx *p, char **map, int level)
{
	t_position	posi;
	const int	*i;

	p->frame++;
	if (p->frame >= level)
	{
		posi = enemys_positioon(map);
		i = point_return(map, p->temp_j);
		p->key = i[0];
		free(p->temp_j);
		p->temp_j = ft_enemy_movement(i, map, posi);
		free((void *)i);
		p->frame = 0;
		if (p->temp_j[0] == 15)
			mlx_loop_hook(p->mlx, draw_loose, (void *)p);
	}
}

void	draw_wall_floor(t_mlx *p, int height, int width, int y)
{
	void	*floor;
	void	*wall;
	int		x;
	char	**map;

	floor = mlx_xpm_file_to_image(p->mlx, "Bonus/textures/Square.xpm", &y, &y);
	wall = mlx_xpm_file_to_image(p->mlx, "Bonus/textures/Wall.xpm", &y, &y);
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

void	destroy_frame_2(t_mlx *params, t_animations *animation, int which)
{
	int	k;

	k = 0;
	if (which == 1)
	{
		while (k < 12)
		{
			if (animation->exit[k] != NULL)
				mlx_destroy_image(params->mlx, animation->exit[k]);
			k++;
		}
	}
	else
	{
		while (k < 12)
		{
			if (animation->coin[k] != NULL)
				mlx_destroy_image(params->mlx, animation->coin[k]);
			k++;
		}
	}
}

void	destroy_frame(t_mlx *params, t_animations *animation, int frame)
{
	int	k;

	k = 0;
	if (frame == 8)
	{
		while (k < frame)
		{
			if (animation->gost[k] != NULL)
				mlx_destroy_image(params->mlx, animation->gost[k]);
			k++;
		}
	}
	else
	{
		while (k < frame)
		{
			if (animation->pacman[k] != NULL)
				mlx_destroy_image(params->mlx, animation->pacman[k]);
			k++;
		}
	}
}
