/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:52:23 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/27 18:48:47 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_enemy(t_mlx *params, int x, int y, int frame)
{
	static t_animations		gost;
	int						i;
	static struct timeval	lst;
	struct timeval			now;
	static int				j;

	i = 64;
	if (params->key == 3 || params->key == 4)
		j = params->key;
	while (frame < 8)
	{
		gost.gost_right[frame] = mlx_xpm_file_to_image(params->mlx,
				load_enemy_texture(frame, j), &i, &i);
		free(load_enemy_texture(frame, j));
		frame++;
	}
	mlx_put_image_to_window(params->mlx, params->win,
		gost.gost_right[gost.frame], x * TS, y * TS);
	gettimeofday(&now, NULL);
	if (now.tv_sec > lst.tv_sec || (now.tv_sec == lst.tv_sec && now.tv_usec
			- lst.tv_usec > 70000))
	{
		gost.frame = (gost.frame + 1) % 8;
		lst = now;
	}
}

void	draw_moves(t_mlx *p, int w, int height)
{
	t_numbers	nums;
	int			x;
	int			y;
	int			digit;
	int			moves;

	moves = p->moves;
	nums = get_numbers(p);
	x = get_x_position(moves, w, 2);
	y = (64 * (height + 1)) - 64;
	if (moves == 0)
	{
		mlx_put_image_to_window(p->mlx, p->win, nums.moves, w / 2, y);
		mlx_put_image_to_window(p->mlx, p->win, nums.digits[0], x, y);
		return ;
	}
	while (moves > 0)
	{
		digit = moves % 10;
		mlx_put_image_to_window(p->mlx, p->win, nums.moves, w / 2, y);
		mlx_put_image_to_window(p->mlx, p->win, nums.digits[digit], x, y);
		moves = moves / 10;
		x = x - 64;
	}
}

void	draw_coin_count(t_mlx *p, int c, int w, int height)
{
	t_numbers	nums;
	int			x;
	int			y;
	int			digit;

	nums = get_numbers(p);
	if (w < 15)
		w = 15;
	x = get_x_position(c, w, 1);
	y = (64 * (height + 1)) - 64;
	if (c == 0)
	{
		mlx_put_image_to_window(p->mlx, p->win, nums.coins, (w - 8) * 64, y);
		mlx_put_image_to_window(p->mlx, p->win, nums.digits[0], x, y);
		return ;
	}
	while (c > 0)
	{
		digit = c % 10;
		mlx_put_image_to_window(p->mlx, p->win, nums.coins, (w - 8) * 64, y);
		mlx_put_image_to_window(p->mlx, p->win, nums.digits[digit], x, y);
		c = c / 10;
		x = x - 64;
	}
}

int	draw_win(t_mlx *p)
{
	void	*loose;
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
	loose = mlx_xpm_file_to_image(p->mlx, "./textures/you_win.xpm", &i, &j);
	mlx_put_image_to_window(p->mlx, p->win, loose, (x * TS) / 2 - i / 2, (y
			* TS) / 2 - j / 2);
	return (0);
}

int	draw_loose(t_mlx *p)
{
	void	*loose;
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
	loose = mlx_xpm_file_to_image(p->mlx, "./textures/you_loose.xpm", &i, &j);
	mlx_put_image_to_window(p->mlx, p->win, loose, (x * TS) / 2 - i / 2, (y
			* TS) / 2 - j / 2);
	return (0);
}
