/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:52:23 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/02 23:54:10 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	draw_moves(t_mlx *p, int w, int height)
{
	t_numbers	nums;
	int			i;
	int			moves;

	i = 0;
	moves = p->moves;
	nums = get_numbers(p);
	if (moves == 0)
		put_image(p, w, height, nums);
	else
		put_frames(p, w, height, nums);
	mlx_destroy_image(p->mlx, nums.moves);
	mlx_destroy_image(p->mlx, nums.coins);
	while (i < 10)
	{
		mlx_destroy_image(p->mlx, nums.digits[i]);
		i++;
	}
}

void	draw_coin_count(t_mlx *p, int c, int w, int height)
{
	t_numbers	nums;
	int			x;
	int			y;
	int			digit;
	int			i;

	digit = 0;
	i = 0;
	nums = get_numbers(p);
	if (w < 15)
		w = 15;
	x = get_x_position(c, w, 1);
	y = (64 * (height + 1)) - 64;
	if (c == 0)
		put_coin_images(p, x, nums);
	else
		put_coin_frames(p, c, nums, digit);
	mlx_destroy_image(p->mlx, nums.coins);
	mlx_destroy_image(p->mlx, nums.moves);
	while (i < 10)
	{
		mlx_destroy_image(p->mlx, nums.digits[i]);
		i++;
	}
}

int	draw_win(t_mlx *p)
{
	void	*win;
	int		i;
	int		j;
	int		x;
	int		y;

	y = 0;
	while (p->map[y])
	{
		x = 0;
		while (p->map[y][x])
			x++;
		y++;
	}
	if (x < 14)
		x = 14;
	if (y < 4)
		y = 4;
	i = 489;
	j = 258;
	win = mlx_xpm_file_to_image(p->mlx, "Bonus/textures/you_win.xpm", &i, &j);
	mlx_put_image_to_window(p->mlx, p->win, win, (x * TS) / 2 - i / 2, (y * TS)
		/ 2 - j / 2);
	mlx_destroy_image(p->mlx, win);
	return (0);
}

int	draw_loose(t_mlx *p)
{
	void	*los;
	int		i;
	int		j;
	int		x;
	int		y;

	y = 0;
	while (p->map[y])
	{
		x = 0;
		while (p->map[y][x])
			x++;
		y++;
	}
	if (x < 14)
		x = 14;
	if (y < 4)
		y = 4;
	i = 489;
	j = 258;
	los = mlx_xpm_file_to_image(p->mlx, "Bonus/textures/you_loose.xpm", &i, &j);
	mlx_put_image_to_window(p->mlx, p->win, los, (x * TS) / 2 - i / 2, (y * TS)
		/ 2 - j / 2);
	mlx_destroy_image(p->mlx, los);
	return (0);
}
