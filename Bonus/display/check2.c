/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:24:20 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/04 16:47:05 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	dst = ft_malloc(sizeof(char) * ft_strlen(src) + 1);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	fill(char **tab, t_point size, t_point begin, char to_fill[])
{
	char	c;
	int		i;

	if (begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x >= size.x)
		return ;
	c = tab[begin.y][begin.x];
	i = 0;
	while (i < 4)
	{
		if (c == to_fill[i])
		{
			tab[begin.y][begin.x] = 'X';
			if (to_fill[i] == 'E')
				return ;
			fill(tab, size, (t_point){begin.x - 1, begin.y}, to_fill);
			fill(tab, size, (t_point){begin.x + 1, begin.y}, to_fill);
			fill(tab, size, (t_point){begin.x, begin.y - 1}, to_fill);
			fill(tab, size, (t_point){begin.x, begin.y + 1}, to_fill);
			break ;
		}
		i++;
	}
}

void	check_map2(char **map2, char **map)
{
	int	i;

	i = 0;
	if (c_count(map2) != 0 || e_find(map2) != 0)
	{
		while (map2[i] != NULL)
		{
			free(map2[i]);
			i++;
		}
		free(map2);
		free_map(map);
	}
	else
	{
		while (map2[i] != NULL)
		{
			free(map2[i]);
			i++;
		}
		free(map2);
	}
}

int	e_find(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_valid(char **map, int x, int y)
{
	t_point	size;
	int		i;
	t_point	begin;
	char	to_fill[4];
	char	**map2;

	to_fill[0] = '0';
	to_fill[1] = 'C';
	to_fill[2] = 'E';
	to_fill[3] = 'S';
	size.x = map_width(map);
	size.y = map_height(map);
	i = 0;
	begin.x = y;
	begin.y = x;
	map2 = ft_malloc(sizeof(char *) * (map_height(map) + 1));
	while (i < map_height(map))
	{
		map2[i] = ft_strcpy(map2[i], map[i]);
		i++;
	}
	map2[i] = NULL;
	fill(map2, size, begin, to_fill);
	check_map2(map2, map);
}
