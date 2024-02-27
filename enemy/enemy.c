/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:53:52 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/27 23:04:05 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	if_ey_is_more(int j, int e_x, int p_x)
{
	int	i;

	i = 0;
	if (j == 0 || j == 2 || j == 3 || j == 4 || j == 11 || j == 12 || j == 13
		|| j == 14)
		i = 1;
	else if (j == 1)
		i = if_equals(j, e_x, p_x);
	else if (j == 5)
		i = if_equals(j, e_x, p_x);
	else if (j == 6 || j == 8)
		i = 4;
	else if (j == 7 || j == 9)
		i = 3;
	else if (j == 10)
		i = 2;
	return (i);
}

int	if_ey_is_less(int j, int e_x, int p_x)
{
	int	i;

	i = 0;
	if (j == 0 || j == 1 || j == 3 || j == 4 || j == 6 || j == 7 || j == 10
		|| j == 14)
		i = 2;
	else if (j == 5)
		i = if_equals(j, e_x, p_x);
	else if (j == 2)
		i = if_equals(j, e_x, p_x);
	else if (j == 8 || j == 11)
		i = 4;
	else if (j == 9 || j == 12)
		i = 3;
	else if (j == 13)
		i = 1;
	return (i);
}

int	if_equals(int j, int e_x, int p_x)
{
	if (e_x > p_x)
	{
		if (j == 0 || j == 1 || j == 2 || j == 4 || j == 5 || j == 7 || j == 9
			|| j == 12)
			return (3);
		else if (j == 3 || j == 11 || j == 14 || j == 13)
			return (1);
		else if (j == 6 || j == 10)
			return (2);
		else if (j == 8)
			return (4);
	}
	else if (e_x < p_x)
	{
		if (j == 0 || j == 1 || j == 2 || j == 3 || j == 5 || j == 6 || j == 8
			|| j == 11)
			return (4);
		else if (j == 4 || j == 12 || j == 13 || j == 14)
			return (1);
		else if (j == 7 || j == 10)
			return (2);
		else if (j == 9)
			return (3);
	}
	return (0);
}

int	*point_return(char **map, int *j)
{
	t_position	posi;
	int			*i;
	int			k;
	int			p_x;
	int			p_y;

	k = 0;
	posi = enemys_positioon(map);
	p_x = player_position(map, 'P', 1);
	p_y = player_position(map, 'P', 2);
	i = (int *)malloc(posi.count * sizeof(int));
	while (k < posi.count)
	{
		if (posi.y[k] > p_y)
			i[k] = if_ey_is_more(j[k], posi.x[k], p_x);
		else if (posi.y[k] < p_y)
			i[k] = if_ey_is_less(j[k], posi.x[k], p_x);
		else if (posi.y[k] == p_y)
			i[k] = if_equals(j[k], posi.x[k], p_x);
		k++;
	}
	return (i);
}
