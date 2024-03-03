/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:59:50 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/02 23:48:29 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*load_enemy_texture(int frame, int key)
{
	char	*c;

	if (key == 4)
		c = combine("Bonus/textures/enemy/right/", frame + 1, ".xpm");
	else if (key == 3)
		c = combine("Bonus/textures/enemy/left/", frame + 1, ".xpm");
	else
		c = combine("Bonus/textures/enemy/right/", frame + 1, ".xpm");
	return (c);
}

char	*load_pacman_texture(int frame, int keycode)
{
	char	*c;

	if (keycode == W)
		c = combine("Bonus/textures/pacman/up/up", frame + 1, ".xpm");
	else if (keycode == S)
		c = combine("Bonus/textures/pacman/down/down", frame + 1, ".xpm");
	else if (keycode == A)
		c = combine("Bonus/textures/pacman/left/left", frame + 1, ".xpm");
	else if (keycode == D)
		c = combine("Bonus/textures/pacman/right/right", frame + 1, ".xpm");
	else
		c = combine("Bonus/textures/pacman/right/right", frame + 1, ".xpm");
	return (c);
}

t_numbers	get_numbers(t_mlx *p)
{
	t_numbers	nums;
	int			i;
	int			j;
	char		digit_char[2];
	char		*c;

	i = 64;
	j = 0;
	nums.coins = mlx_xpm_file_to_image(p->mlx, "Bonus/textures/coins.xpm", &i,
			&i);
	nums.moves = mlx_xpm_file_to_image(p->mlx, "Bonus/textures/moves.xpm", &i,
			&i);
	while (j < 10)
	{
		digit_char[0] = '0' + j;
		digit_char[1] = '\0';
		c = combines("Bonus/textures/nums/", digit_char, ".xpm");
		nums.digits[j] = mlx_xpm_file_to_image(p->mlx, c, &i, &i);
		free(c);
		j++;
	}
	return (nums);
}

int	get_x_position(int moves, int width, int which)
{
	int	x;

	x = 0;
	if (which == 1)
	{
		if (ft_int_lent(moves) == 1)
			x = ((width - 8) * 64 + 330) - ft_int_lent(moves) * 64;
		else
			x = ((width - 8) * 64 + 330 + 125 * (ft_int_lent(moves) - 1))
				- ft_int_lent(moves) * 64;
	}
	else if (which == 2)
	{
		if (ft_int_lent(moves) == 1)
			x = (width + 320) - ft_int_lent(moves) * 64;
		else
			x = ((width + 320) + 125 * (ft_int_lent(moves) - 1))
				- ft_int_lent(moves) * 64;
	}
	return (x);
}

t_info	numbers_return(t_mlx params, int i)
{
	t_info	info;
	int		height;
	int		width;
	int		key;
	char	**map;

	map = params.map;
	i = 64;
	height = 0;
	while (map[height])
		height++;
	width = 0;
	while (map[0][width])
		width++;
	key = D;
	info.height = height;
	info.width = width;
	info.x = player_position(map, 'P', 1);
	info.y = player_position(map, 'P', 2);
	info.enemy_x = player_position(map, 'S', 1);
	info.enemy_y = player_position(map, 'S', 2);
	return (info);
}
