/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:54:30 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/02 23:24:45 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	update_frame(t_animations *gost, struct timeval *lst, int speed,
		int frame)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	if (now.tv_sec > lst->tv_sec || (now.tv_sec == lst->tv_sec && now.tv_usec
			- lst->tv_usec > speed))
	{
		gost->frame = (gost->frame + 1) % frame;
		*lst = now;
	}
}

void	put_image(t_mlx *p, int w, int height, t_numbers nums)
{
	int	x;
	int	y;
	int	moves;

	moves = p->moves;
	if (w < 15)
		w = 15;
	x = get_x_position(moves, w, 2);
	y = (64 * (height + 1)) - 64;
	mlx_put_image_to_window(p->mlx, p->win, nums.moves, w / 2, y);
	mlx_put_image_to_window(p->mlx, p->win, nums.digits[0], x, y);
}

void	put_frames(t_mlx *p, int w, int height, t_numbers nums)
{
	int	x;
	int	y;
	int	moves;

	moves = p->moves;
	if (w < 15)
		w = 15;
	x = get_x_position(moves, w, 2);
	y = (64 * (height + 1)) - 64;
	while (moves > 0)
	{
		mlx_put_image_to_window(p->mlx, p->win, nums.moves, w / 2, y);
		mlx_put_image_to_window(p->mlx, p->win, nums.digits[moves % 10], x, y);
		moves = moves / 10;
		x = x - 64;
	}
}

void	put_coin_images(t_mlx *p, int x, t_numbers nums)
{
	int		y;
	t_info	info;

	info = numbers_return(*p, 0);
	if (info.width < 15)
		info.width = 15;
	y = (64 * (info.height + 1)) - 64;
	mlx_put_image_to_window(p->mlx, p->win, nums.coins, (info.width - 8) * 64,
		y);
	mlx_put_image_to_window(p->mlx, p->win, nums.digits[0], x, y);
}

void	put_coin_frames(t_mlx *p, int c, t_numbers nums, int digit)
{
	int		x;
	int		y;
	t_info	info;

	info = numbers_return(*p, 0);
	x = get_x_position(c, info.width, 1);
	y = (64 * (info.height + 1)) - 64;
	while (c > 0)
	{
		digit = c % 10;
		mlx_put_image_to_window(p->mlx, p->win, nums.coins, (info.width - 8)
			* 64, y);
		mlx_put_image_to_window(p->mlx, p->win, nums.digits[digit], x, y);
		c = c / 10;
		x = x - 64;
	}
}
