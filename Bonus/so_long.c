/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:50:24 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/04 16:46:57 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

char	**get_map(char *av)
{
	char	**map;
	int		i;
	int		fd;
	char	*c;

	c = ft_strjoin("Bonus/maps/", av);
	fd = open(c, O_RDONLY);
	free(c);
	if (fd == -1)
		ft_error();
	map = ft_malloc(sizeof(char *) * MAP_SIZE);
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

t_mlx	*get_param(char *av[])
{
	t_mlx	*par;

	par = ft_malloc(sizeof(t_mlx));
	par->map = get_map(av[1]);
	par->frame = 0;
	par->temp_j = ft_malloc(sizeof(int) * 2);
	par->temp_j[0] = 1;
	par->mlx = mlx_init();
	par->keycode = D;
	par->moves = 0;
	par->key = 3;
	return (par);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_mlx	*par;

	par = get_param(av);
	check_ac(par, ac, av);
	info = numbers_return(*par, ac);
	if (info.width < 14)
		info.width = 14;
	par->win = mlx_new_window(par->mlx, (info.width - 1) * 64, (info.height + 1)
			* 64, "So_Long");
	mlx_hook(par->win, 17, 1L << 0, exit_game, (void *)par);
	mlx_key_hook(par->win, key_hook, (void *)par);
	mlx_loop_hook(par->mlx, draw_everything, (void *)par);
	mlx_loop(par->mlx);
	free((void *)par);
	return (0);
}
