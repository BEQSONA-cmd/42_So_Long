/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:15:25 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/21 23:23:37 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_window(void **params)
{
	mlx_destroy_window(params[0], params[1]);
	ft_printf(GREEN "PERFECT\n" RESET);
	exit(0);
}

int	exit_check(int keycode, char **map, int x, int y, int c)
{
	if (keycode == 119 && map[y - 1][x] == 'E' && c == 0)
	{
		map[y][x] = '0';
		y--;
		map[y][x] = 'P';
		return (1);
	}
	else if (keycode == 115 && map[y + 1][x] == 'E' && c == 0)
	{
		map[y][x] = '0';
		y++;
		map[y][x] = 'P';
		return (1);
	}
	else if (keycode == 97 && map[y][x - 1] == 'E' && c == 0)
	{
		map[y][x] = '0';
		x--;
		map[y][x] = 'P';
		return (1);
	}
	else if (keycode == 100 && map[y][x + 1] == 'E' && c == 0)
	{
		map[y][x] = '0';
		x++;
		map[y][x] = 'P';
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

int	*player_position(char **map)
{
	int	i;
	int	y;
	int	x;
	int	*pos;

	i = 0;
	y = 0;
	x = 0;
	pos = (int *)malloc(2 * sizeof(int));
	while (map[y] != NULL && !i)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				pos[0] = x;
				pos[1] = y;
				break ;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

t_info	numbers_return(void **params, int i)
{
	t_info	info;
	int		height;
	int		width;
	int		key;
	char	**map;

	map = params[2];
	i = 64;
	info.floor = mlx_xpm_file_to_image(params[0], "textures/Square.xpm", &i,
			&i);
	info.wall = mlx_xpm_file_to_image(params[0], "textures/Wall.xpm", &i, &i);
	height = 0;
	while (map[height])
		height++;
	width = 0;
	while (map[0][width])
		width++;
	key = 100;
	info.height = height;
	info.width = width;
	info.x = player_position(map)[0];
	info.y = player_position(map)[1];
	return (info);
}

int	c_count(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}
