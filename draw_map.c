/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 00:27:58 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/18 00:48:03 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_textures(t_textures textures)
{
	if (!textures.floor || !textures.wall || !textures.left || !textures.right
		|| !textures.up || !textures.down)
	{
		ft_printf("Error\n");
		exit(1);
	}
}

t_textures	get_textures(void *mlx, int last_key)
{
	t_textures	textures;
	int			i;

	i = 64;
	textures.floor = mlx_xpm_file_to_image(mlx, "textures/Square.xpm", &i, &i);
	textures.wall = mlx_xpm_file_to_image(mlx, "textures/Wall.xpm", &i, &i);
	textures.left = mlx_xpm_file_to_image(mlx, "textures/Left.xpm", &i, &i);
	textures.right = mlx_xpm_file_to_image(mlx, "textures/Right.xpm", &i, &i);
	textures.up = mlx_xpm_file_to_image(mlx, "textures/Up.xpm", &i, &i);
	textures.down = mlx_xpm_file_to_image(mlx, "textures/Down.xpm", &i, &i);
	ft_check_textures(textures);
	if (last_key == 97)
		textures.img = textures.left;
	else if (last_key == 100)
		textures.img = textures.right;
	else if (last_key == 119)
		textures.img = textures.up;
	else if (last_key == 115)
		textures.img = textures.down;
	else
		textures.img = textures.right;
	return (textures);
}

void	draw_map(void *mlx, void *win, char **map, int last_key)
{
	unsigned long	y;
	unsigned long	x;
	t_textures		text;
	t_info			info;

	info = numbers_return(map);
	text = get_textures(mlx, last_key);
	y = 0;
	while (y < info.height)
	{
		x = 0;
		while (x < info.width)
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx, win, text.floor, x * TS, y * TS);
			else if (map[y][x] == '0')
				mlx_put_image_to_window(mlx, win, text.wall, x * TS, y * TS);
			else if (map[y][x] == 'P')
				mlx_put_image_to_window(mlx, win, text.img, x * TS, y * TS);
			x++;
		}
		y++;
	}
}

char	**get_map(void)
{
	char	**map;
	int		i;
	int		fd;

	fd = open("./maps/map2.ber", O_RDONLY);
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
