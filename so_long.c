/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:50:24 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/22 21:54:56 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char *av)
{
	char	**map;
	int		i;
	int		fd;
	char	*c;

	c = ft_strjoin("./maps/", av);
	fd = open(c, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Failed to open file\n");
		exit(1);
	}
	map = malloc(1000 * sizeof(char));
	i = 0;
	map[i] = get_next_line(fd);
	while (map[i])
	{
		i++;
		map[i] = get_next_line(fd);
	}
	map[i] = NULL;
	check_map(map);
	close(fd);
	return (map);
}

int	main(int ac, char **av)
{
	t_info	info;
	char	*c;
	t_mlx	*par;

	par = malloc(sizeof(t_mlx));
	par->map = get_map(av[1]);
	par->mlx = mlx_init();
	ft_printf("%d/0\n", c_count(par->map));
	c = ft_itoa(c_count(par->map));
	info = numbers_return(*par, ac);
	par->win = mlx_new_window(par->mlx, (info.width - 1) * 64, (info.height + 1)
			* 64, "Pac_Man");
	mlx_key_hook(par->win, key_hook, (void *)par);
	mlx_loop_hook(par->mlx, draw_map, (void *)par);
	mlx_loop(par->mlx);
	free(par->map);
	return (0);
}
