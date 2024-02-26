/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:59:50 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/26 23:49:53 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*load_enemy_texture(int frame, int key)
{
	char	*c;

	if (key == 4)
		c = combine("textures/enemy/right/", frame + 1, ".xpm");
	else if (key == 3)
		c = combine("textures/enemy/left/", frame + 1, ".xpm");
	else
		c = combine("textures/enemy/right/", frame + 1, ".xpm");
	return (c);
}

char	*load_pacman_texture(int frame, int keycode)
{
	char	*c;

	if (keycode == W)
		c = combine("textures/pacman/up/up", frame + 1, ".xpm");
	else if (keycode == S)
		c = combine("textures/pacman/down/down", frame + 1, ".xpm");
	else if (keycode == A)
		c = combine("textures/pacman/left/left", frame + 1, ".xpm");
	else if (keycode == D)
		c = combine("textures/pacman/right/right", frame + 1, ".xpm");
	else
		c = combine("textures/pacman/right/right", frame + 1, ".xpm");
	return (c);
}

t_numbers	get_numbers(t_mlx *p)
{
	t_numbers	nums;
	int			i;
	int			j;
	char		digit_char[2];

	i = 64;
	j = 0;
	nums.coins = mlx_xpm_file_to_image(p->mlx, "./textures/coins.xpm", &i, &i);
	nums.moves = mlx_xpm_file_to_image(p->mlx, "./textures/moves.xpm", &i, &i);
	while (j < 10)
	{
		digit_char[0] = '0' + j;
		digit_char[1] = '\0';
		nums.digits[j] = mlx_xpm_file_to_image(p->mlx,
				combines("./textures/nums/", digit_char, ".xpm"), &i, &i);
		j++;
	}
	return (nums);
}

void	draw_coin_count(t_mlx *p, int c, int width, int height)
{
	t_numbers	nums;
	int			x;
	int			y;
	int			digit;

	nums = get_numbers(p);
	if (ft_int_lent(c) == 1)
		x = (width + 320) - ft_int_lent(c) * 64;
	else
		x = (width + 440) - ft_int_lent(c) * 64;
	y = (64 * (height + 1)) - 64;
	if (c == 0)
	{
		mlx_put_image_to_window(p->mlx, p->win, nums.coins, width / 2, y);
		mlx_put_image_to_window(p->mlx, p->win, nums.digits[0], x, y);
		return ;
	}
	while (c > 0)
	{
		digit = c % 10;
		mlx_put_image_to_window(p->mlx, p->win, nums.coins, width / 2, y);
		mlx_put_image_to_window(p->mlx, p->win, nums.digits[digit], x, y);
		c = c / 10;
		x = x - 64;
	}
}

void	draw_moves(t_mlx *p, int width, int height)
{
	t_numbers	nums;
	int			x;
	int			y;
	int			digit;
	int			moves;

	moves = p->moves;
	nums = get_numbers(p);
	if (ft_int_lent(moves) == 1)
		x = ((width - 8) * 64 + 330) - ft_int_lent(moves) * 64;
	else
		x = ((width - 8) * 64 + 330 + 125 * (ft_int_lent(moves) - 1))
			- ft_int_lent(moves) * 64;
	y = (64 * (height + 1)) - 64;
	if (moves == 0)
	{
		mlx_put_image_to_window(p->mlx, p->win, nums.moves, (width - 8) * 64,
			y);
		mlx_put_image_to_window(p->mlx, p->win, nums.digits[0], x, y);
		return ;
	}
	while (moves > 0)
	{
		digit = moves % 10;
		mlx_put_image_to_window(p->mlx, p->win, nums.moves, (width - 8) * 64,
			y);
		mlx_put_image_to_window(p->mlx, p->win, nums.digits[digit], x, y);
		moves = moves / 10;
		x = x - 64;
	}
}
