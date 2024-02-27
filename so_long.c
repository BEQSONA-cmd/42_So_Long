/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:50:24 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/27 23:41:43 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	write(2, "Error\n", 6);
	exit(1);
}

char	**get_map(char *av)
{
	char	**map;
	int		i;
	int		fd;
	char	*c;

	c = ft_strjoin("./maps/", av);
	fd = open(c, O_RDONLY);
	free(c);
	if (fd == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	map = malloc(sizeof(char *) * MAP_SIZE);
	i = 0;
	while (1)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	check_map(map);
	close(fd);
	return (map);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_mlx	*par;

	if (ac != 2)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	par = malloc(sizeof(t_mlx));
	par->map = get_map(av[1]);
	par->frame = 0;
	par->temp_j = malloc(MAP_SIZE * sizeof(int));
	par->mlx = mlx_init();
	info = numbers_return(*par, ac);
	if (info.width < 14)
		info.width = 14;
	par->win = mlx_new_window(par->mlx, (info.width - 1) * 64, (info.height + 1)
			* 64, "So_Long");
	mlx_key_hook(par->win, key_hook, (void *)par);
	mlx_loop_hook(par->mlx, draw_everything, (void *)par);
	mlx_loop(par->mlx);
	return (0);
}
