/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:57:46 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/26 14:52:44 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*load_enemy_texture(int frame, int key)
{
	char	*c;

	if (key == 1)
		c = combine("textures/enemy/right/", frame + 1, ".xpm");
	else if (key == 2)
		c = combine("textures/enemy/left/", frame + 1, ".xpm");
	else
		c = combine("textures/enemy/right/", frame + 1, ".xpm");
	return (c);
}

void	draw_enemy(t_mlx *params, int x, int y, int frame)
{
	static t_animations		gost;
	char					*c;
	int						i;
	static struct timeval	lst;
	struct timeval			now;
	char					**map;

	i = 64;
	map = params->map;
	while (frame < 8)
	{
		c = load_enemy_texture(frame, 1);
		gost.gost_right[frame] = mlx_xpm_file_to_image(params->mlx, c, &i, &i);
		frame++;
	}
	mlx_put_image_to_window(params->mlx, params->win,
		gost.gost_right[gost.frame], x * TS, y * TS);
	gettimeofday(&now, NULL);
	if (now.tv_sec > lst.tv_sec || (now.tv_sec == lst.tv_sec && now.tv_usec
			- lst.tv_usec > 70000))
	{
		gost.frame = (gost.frame + 1) % 8;
		lst = now;
	}
}

int	ft_enemy_movement(int point, char **map, int x, int y)
{
	static int	i;
	int	j;

	j = 0;
	i = ft_find_one(point, map, x, y);
	if (point == 1 && map[y - 1][x] != '1' && map[y - 1][x] != 'E')
	{
		j = enemy_move(map, x, y, 1);
		if (j == 1)
			return (15);
	}
	else if (point == 2 && map[y + 1][x] != '1' && map[y + 1][x] != 'E')
	{
		j = enemy_move(map, x, y, 2);
		if (j == 1)
			return (15);
	}
	else if (point == 3 && map[y][x - 1] != '1' && map[y][x - 1] != 'E')
	{
		j = enemy_move(map, x, y, 3);
		if (j == 1)
			return (15);
	}
	else if (point == 4 && map[y][x + 1] != '1' && map[y][x + 1] != 'E')
	{
		j = enemy_move(map, x, y, 4);
		if (j == 1)
			return (15);
	}
	return (i);
}

int	enemy_move(char **map, int x, int y, int num)
{
	if (num == 1)
	{
		if (map[y - 1][x] == 'C')
			map[y][x] = 'C';
		else if (map[y - 1][x] == 'P')
			return (1);
		else
			map[y][x] = '0';
		y--;
		map[y][x] = 'S';
	}
	else if (num == 2)
	{
		if (map[y + 1][x] == 'C')
			map[y][x] = 'C';
		else if (map[y + 1][x] == 'P')
			return (1);
		else
			map[y][x] = '0';
		y++;
		map[y][x] = 'S';
	}
	else if (num == 3)
	{
		if (map[y][x - 1] == 'C')
			map[y][x] = 'C';
		else if (map[y][x - 1] == 'P')
			return (1);
		else
			map[y][x] = '0';
		x--;
		map[y][x] = 'S';
	}
	else if (num == 4)
	{
		if (map[y][x + 1] == 'C')
			map[y][x] = 'C';
		else if (map[y][x + 1] == 'P')
			return (1);
		else
			map[y][x] = '0';
		x++;
		map[y][x] = 'S';
	}
	return (0);
}

int	point_return(char **map, int j)
{
	int	*pos;
	int	p_x;
	int	p_y;
	int	e_x;
	int	e_y;
	int	i;

	i = 0;
	pos = player_position(map);
	p_x = pos[0];
	p_y = pos[1];
	free(pos);
	pos = enemy_position(map);
	e_x = pos[0];
	e_y = pos[1];
	free(pos);
	if (e_y > p_y)
	{
		if (j == 0 || j == 2 || j == 3 || j == 4 || j == 11 || j == 12
			|| j == 13 || j == 14)
			i = 1;
		else if (j == 1)
		{
			if (e_x > p_x)
				i = 3;
			else if (e_x < p_x)
				i = 4;
			else
				i = 3;
		}
		else if (j == 5)
		{
			if (e_x > p_x)
				i = 3;
			else
				i = 4;
		}
		else if (j == 6 || j == 8)
			i = 4;
		else if (j == 7 || j == 9)
			i = 3;
		else if (j == 10)
			i = 2;
	}
	else if (e_y < p_y)
	{
		if (j == 0 || j == 1 || j == 3 || j == 4 || j == 6 || j == 7 || j == 10
			|| j == 14)
			i = 2;
		else if (j == 5)
		{
			if (e_x > p_x)
				i = 3;
			else
				i = 4;
		}
		else if (j == 2)
		{
			if (e_x > p_x)
				i = 3;
			else if (e_x < p_x)
				i = 4;
			else
				i = 3;
		}
		else if (j == 8 || j == 11)
			i = 4;
		else if (j == 9 || j == 12)
			i = 3;
		else if (j == 13)
			i = 1;
	}
	else if (e_y == p_y)
	{
		if (e_x > p_x)
		{
			if (j == 0 || j == 1 || j == 2 || j == 4 || j == 5 || j == 7
				|| j == 9 || j == 12)
				i = 3;
			else if (j == 3 || j == 11 || j == 14 || j == 13)
				i = 1;
			else if (j == 6 || j == 10)
				i = 2;
			else if (j == 8)
				i = 4;
		}
		else if (e_x < p_x)
		{
			if (j == 0 || j == 1 || j == 2 || j == 3 || j == 5 || j == 6
				|| j == 8 || j == 11)
				i = 4;
			else if (j == 4 || j == 12 || j == 13 || j == 14)
				i = 1;
			else if (j == 7 || j == 10)
				i = 2;
			else if (j == 9)
				i = 3;
		}
	}
	return (i);
}

int	ft_find_one(int point, char **map, int x, int y)
{
	if (map[y - 1][x] == '1' && point == 1)
	{
		if (map[y + 1][x] == '1')
		{
			if (map[y][x - 1] == '1')
				return (8);
			else if (map[y][x + 1] == '1')
				return (9);
			return (5);
		}
		if (map[y][x - 1] == '1')
		{
			if (map[y][x + 1] == '1')
				return (10);
			return (6);
		}
		else if (map[y][x + 1] == '1')
			return (7);
		return (1);
	}
	if (map[y + 1][x] == '1' && point == 2)
	{
		if (map[y - 1][x] == '1')
		{
			if (map[y][x - 1] == '1')
				return (8);
			else if (map[y][x + 1] == '1')
				return (9);
			return (5);
		}
		if (map[y][x - 1] == '1')
		{
			if (map[y][x + 1] == '1')
				return (13);
			return (11);
		}
		else if (map[y][x + 1] == '1')
			return (12);
		return (2);
	}
	if (map[y][x - 1] == '1' && point == 3)
	{
		if (map[y - 1][x] == '1')
		{
			if (map[y + 1][x] == '1')
				return (8);
			else if (map[y][x + 1] == '1')
				return (10);
			return (6);
		}
		if (map[y + 1][x] == '1')
		{
			if (map[y][x + 1] == '1')
				return (13);
			return (11);
		}
		else if (map[y][x + 1] == '1')
			return (14);
		return (3);
	}
	if (map[y][x + 1] == '1' && point == 4)
	{
		if (map[y - 1][x] == '1')
		{
			if (map[y + 1][x] == '1')
				return (9);
			else if (map[y][x - 1] == '1')
				return (10);
			return (7);
		}
		if (map[y + 1][x] == '1')
		{
			if (map[y][x - 1] == '1')
				return (13);
			return (12);
		}
		else if (map[y][x - 1] == '1')
			return (14);
		return (4);
	}
	else
		return (0);
}
