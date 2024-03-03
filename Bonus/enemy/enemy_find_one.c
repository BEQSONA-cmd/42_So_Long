/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_find_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:47:11 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/02 23:24:51 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_find_one_1(char **map, int x, int y)
{
	if (map[y + 1][x] == '1')
	{
		if (map[y][x - 1] == '1')
			return (8);
		else if (map[y][x + 1] == '1')
			return (9);
		return (5);
	}
	else if (map[y][x - 1] == '1')
	{
		if (map[y][x + 1] == '1')
			return (10);
		return (6);
	}
	else if (map[y][x + 1] == '1')
		return (7);
	return (1);
}

int	ft_find_one_2(char **map, int x, int y)
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

int	ft_find_one_3(char **map, int x, int y)
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

int	find_one_4(char **map, int x, int y)
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

int	ft_find_one(int point, char **map, int x, int y)
{
	int	i;

	i = 0;
	if (map[y - 1][x] == '1' && point == 1)
		i = ft_find_one_1(map, x, y);
	if (map[y + 1][x] == '1' && point == 2)
		i = ft_find_one_2(map, x, y);
	if (map[y][x - 1] == '1' && point == 3)
		i = ft_find_one_3(map, x, y);
	if (map[y][x + 1] == '1' && point == 4)
		i = find_one_4(map, x, y);
	return (i);
}
