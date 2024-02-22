/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:08:39 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/22 20:37:19 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(t_mlx *p)
{
	int		y;
	int		x;
	t_info	info;
	char	**map;

	map = p->map;
	info = numbers_return(*p, 0);
	y = 0;
	while (y < info.height)
	{
		x = 0;
		while (x < info.width)
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(p->mlx, p->win, info.floor, x * TS, y
					* TS);
			else if (map[y][x] == '0')
				mlx_put_image_to_window(p->mlx, p->win, info.wall, x * TS, y
					* TS);
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

int	exit_check(int keycode, char **map, int x, int y, int c)
{
	if (keycode == 119 && map[y - 1][x] == 'E' && c == 0)
	{
		ft_move(map, x, y, 1);
		return (1);
	}
	else if (keycode == 115 && map[y + 1][x] == 'E' && c == 0)
	{
		ft_move(map, x, y, 2);
		return (1);
	}
	else if (keycode == 97 && map[y][x - 1] == 'E' && c == 0)
	{
		ft_move(map, x, y, 3);
		return (1);
	}
	else if (keycode == 100 && map[y][x + 1] == 'E' && c == 0)
	{
		ft_move(map, x, y, 4);
		return (1);
	}
	return (0);
}

void	check_c(int keycode, char **map, int x, int y, int c)
{
	static int	i;

	if (keycode == 119 && map[y - 1][x] == 'C')
	{
		i++;
		printf("%d/%d\n", c + i - 1, i);
	}
	else if (keycode == 115 && map[y + 1][x] == 'C')
	{
		i++;
		printf("%d/%d\n", c + i - 1, i);
	}
	else if (keycode == 97 && map[y][x - 1] == 'C')
	{
		i++;
		printf("%d/%d\n", c + i - 1, i);
	}
	else if (keycode == 100 && map[y][x + 1] == 'C')
	{
		i++;
		printf("%d/%d\n", c + i - 1, i);
	}
}
