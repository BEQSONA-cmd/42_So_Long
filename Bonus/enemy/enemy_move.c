/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:43:24 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/02 23:24:55 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	enemy_move_1(char **map, int x, int y)
{
	if (map[y - 1][x] == 'C')
		map[y][x] = 'C';
	else if (map[y - 1][x] == 'S')
		map[y][x] = 'S';
	else if (map[y - 1][x] == 'P')
		return (1);
	else
		map[y][x] = '0';
	y--;
	map[y][x] = 'S';
	return (0);
}

int	enemy_move_2(char **map, int x, int y)
{
	if (map[y + 1][x] == 'C')
		map[y][x] = 'C';
	else if (map[y + 1][x] == 'S')
		map[y][x] = 'S';
	else if (map[y + 1][x] == 'P')
		return (1);
	else
		map[y][x] = '0';
	y++;
	map[y][x] = 'S';
	return (0);
}

int	enemy_move_3(char **map, int x, int y)
{
	if (map[y][x - 1] == 'C')
		map[y][x] = 'C';
	else if (map[y][x - 1] == 'S')
		map[y][x] = 'S';
	else if (map[y][x - 1] == 'P')
		return (1);
	else
		map[y][x] = '0';
	x--;
	map[y][x] = 'S';
	return (0);
}

int	enemy_move_4(char **map, int x, int y)
{
	if (map[y][x + 1] == 'C')
		map[y][x] = 'C';
	else if (map[y][x + 1] == 'S')
		map[y][x] = 'S';
	else if (map[y][x + 1] == 'P')
		return (1);
	else
		map[y][x] = '0';
	x++;
	map[y][x] = 'S';
	return (0);
}

int	enemy_move(char **map, int x, int y, int num)
{
	int	i;

	i = 0;
	if (num == 1)
		i = enemy_move_1(map, x, y);
	else if (num == 2)
		i = enemy_move_2(map, x, y);
	else if (num == 3)
		i = enemy_move_3(map, x, y);
	else if (num == 4)
		i = enemy_move_4(map, x, y);
	return (i);
}
