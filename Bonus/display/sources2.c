/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:23:00 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/02 23:24:37 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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

int	exit_game(void)
{
	exit(0);
	return (0);
}

void	free_window(t_mlx params)
{
	mlx_destroy_window(params.mlx, params.win);
	exit(0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	ft_error();
}
