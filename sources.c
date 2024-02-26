/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:15:25 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/26 21:27:36 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_position	enemys_positioon(char **map)
{
	int			y;
	int			x;
	t_position	pos;

	y = 0;
	x = 0;
	pos.x = (int *)malloc(100 * sizeof(int));
	pos.y = (int *)malloc(100 * sizeof(int));
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

int	*enemy_position(char **map)
{
	int	y;
	int	x;
	int	*pos;

	y = 0;
	x = 0;
	pos = (int *)malloc(2 * sizeof(int));
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'S')
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

int	*player_position(char **map)
{
	int	y;
	int	x;
	int	*pos;

	y = 0;
	x = 0;
	pos = (int *)malloc(2 * sizeof(int));
	while (map[y] != NULL)
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

int	from_zero(char **map, int *previous_c)
{
	int	i;
	int	j;
	int	current_c;

	current_c = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				current_c++;
			j++;
		}
		i++;
	}
	current_c = *previous_c - (current_c - 1);
	return (current_c - 1);
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
