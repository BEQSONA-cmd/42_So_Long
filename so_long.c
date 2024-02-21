/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:50:24 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/21 23:28:41 by btvildia         ###   ########.fr       */
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
	close(fd);
	return (map);
}

int	main(int ac, char **av)
{
	void	*par[3];
	t_info	info;
	char	*c;

	par[2] = get_map(av[1]);
	par[0] = mlx_init();
	c = ft_itoa(c_count(par[2]));
	info = numbers_return(par, ac);
	par[1] = mlx_new_window(par[0], (info.width - 1) * 64, (info.height + 1)
			* 64, "Pac_Man");
	mlx_key_hook(par[1], key_hook, &par);
	mlx_loop_hook(par[0], draw_map, &par);
	mlx_loop(par[0]);
	free(par[2]);
	return (0);
}
