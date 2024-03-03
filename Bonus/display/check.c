/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:54:20 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/02 23:24:11 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_ones(char **c)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(c[i]) - 1;
	while (c[i])
	{
		if (c[i][0] != '1' || c[i][j - 1] != '1')
			free_map(c);
		i++;
	}
	j = 0;
	while (j < ft_strlen(c[0]) - 1)
	{
		if (c[0][j] != '1' || c[i - 1][j] != '1')
			free_map(c);
		j++;
	}
	check_double(c, 'P');
	check_double(c, 'E');
	check_square(c);
}

void	check_square(char **c)
{
	int	i;
	int	j;

	i = 0;
	while (c[i + 1])
	{
		if (ft_strlen(c[i]) == ft_strlen(c[i + 1]))
		{
			if (c[i + 2] == NULL)
				free_map(c);
		}
		if (ft_strlen(c[i]) != ft_strlen(c[i + 1]))
		{
			j = ft_strlen(c[i + 1]);
			if (c[i + 2] == NULL && ft_strlen(c[i]) - 1 == j)
				return ;
			free_map(c);
		}
		i++;
	}
}

void	check_double(char **c, char a)
{
	int	i;
	int	j;
	int	x;

	x = 1;
	i = 0;
	while (c[i])
	{
		j = 0;
		while (c[i][j])
		{
			if (c[i][j] == a)
			{
				x++;
				if (x > 2)
					free_map(c);
			}
			j++;
		}
		i++;
	}
}

void	check_map(char **c)
{
	int	i;
	int	j;
	int	x;
	int	y;

	if (c == NULL || c[0] == NULL)
		free_map(c);
	i = 0;
	while (c[i])
	{
		j = 0;
		while (c[i][j])
		{
			if (c[i][j] != '0' && c[i][j] != '1' && c[i][j] != 'C'
				&& c[i][j] != 'S' && c[i][j] != 'E' && c[i][j] != 'P'
				&& c[i][j] != '\n')
				free_map(c);
			j++;
		}
		i++;
	}
	x = player_position(c, 'P', 1);
	y = player_position(c, 'P', 2);
	check_valid(c, x, y);
	check_ones(c);
}

int	exit_check(int keycode, char **map, int x, int y)
{
	int	c;

	c = c_count(map);
	if (keycode == W && map[y - 1][x] == 'E' && c == 0)
	{
		ft_move(map, x, y, 1);
		return (1);
	}
	else if (keycode == S && map[y + 1][x] == 'E' && c == 0)
	{
		ft_move(map, x, y, 2);
		return (1);
	}
	else if (keycode == A && map[y][x - 1] == 'E' && c == 0)
	{
		ft_move(map, x, y, 3);
		return (1);
	}
	else if (keycode == D && map[y][x + 1] == 'E' && c == 0)
	{
		ft_move(map, x, y, 4);
		return (1);
	}
	return (0);
}
