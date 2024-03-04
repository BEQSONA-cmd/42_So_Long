/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:14:14 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/04 17:00:58 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**get_map(char *av)
{
	char	**map;
	int		i;
	int		fd;
	char	*c;

	c = ft_strjoin("Mandatory/maps/", av);
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
	par->mlx = mlx_init();
	par->keycode = D;
	par->moves = 0;
	return (par);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_mlx	*par;

	if (ac != 2)
		ft_error();
	par = get_param(av);
	info = numbers_return(*par, ac);
	par->win = mlx_new_window(par->mlx, (info.width - 1) * 64, (info.height)
			* 64, "Pac_Man");
	mlx_hook(par->win, 17, 1L << 0, exit_game, (void *)par);
	mlx_key_hook(par->win, key_hook, (void *)par);
	mlx_loop(par->mlx);
	free((void *)par);
	return (0);
}
