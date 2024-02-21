/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:50:24 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/18 20:39:24 by btvildia         ###   ########.fr       */
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
		exit(EXIT_FAILURE);
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
	void	*params[3];
	t_info	info;

	if (ac != 2)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	info = numbers_return(get_map(av[1]));
	params[0] = mlx_init();
	params[1] = mlx_new_window(params[0], (info.width - 1) * 64, info.height
			* 64, "Pac_Man");
	params[2] = get_map(av[1]);
	mlx_key_hook(params[1], key_hook, &params);
	mlx_loop_hook(params[0], loop_hook, &params);
	mlx_loop(params[0]);
	free(params[2]);
	return (0);
}
