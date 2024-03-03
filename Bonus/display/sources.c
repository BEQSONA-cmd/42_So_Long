/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:15:25 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/02 23:24:32 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_ac(t_mlx *par, int ac, char **av)
{
	if (ac != 2)
	{
		if (ac == 3)
			par->level = av[2];
		else
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	else if (ac == 2)
		par->level = NULL;
}

int	map_width(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

t_position	enemys_positioon(char **map)
{
	int			y;
	int			x;
	t_position	pos;

	y = 0;
	x = 0;
	pos.x = (int *)malloc(MAP_SIZE * sizeof(int));
	pos.y = (int *)malloc(MAP_SIZE * sizeof(int));
	pos.count = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'S')
			{
				pos.x[pos.count] = x;
				pos.y[pos.count] = y;
				pos.count++;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

int	player_position(char **map, char c, int which)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == c)
			{
				if (which == 1)
					return (x);
				else if (which == 2)
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
