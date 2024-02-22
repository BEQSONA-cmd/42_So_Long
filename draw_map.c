/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:12:40 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/22 19:12:40 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*load_pacman_texture(int frame, int keycode)
{
	char	*c;

	if (keycode == 119)
		c = combine("textures/pacman/up/up", frame + 1, ".xpm");
	else if (keycode == 115)
		c = combine("textures/pacman/down/down", frame + 1, ".xpm");
	else if (keycode == 97)
		c = combine("textures/pacman/left/left", frame + 1, ".xpm");
	else if (keycode == 100)
		c = combine("textures/pacman/right/right", frame + 1, ".xpm");
	else
		c = combine("textures/pacman/right/right", frame + 1, ".xpm");
	return (c);
}

void	draw_pacman(t_mlx *params, int x, int y, int frame)
{
	static t_animations		exit;
	char					*c;
	int						i;
	static struct timeval	lst;
	struct timeval			now;

	i = 64;
	while (frame < 10)
	{
		c = load_pacman_texture(frame, params->keycode);
		exit.exit[frame] = mlx_xpm_file_to_image(params->mlx, c, &i, &i);
		frame++;
	}
	mlx_put_image_to_window(params->mlx, params->win, exit.exit[exit.frame], x
		* TS, y * TS);
	gettimeofday(&now, NULL);
	if (now.tv_sec > lst.tv_sec || (now.tv_sec == lst.tv_sec && now.tv_usec
			- lst.tv_usec > 30000))
	{
		exit.frame = (exit.frame + 1) % 10;
		lst = now;
	}
}

void	draw_exit(t_mlx *params, int x, int y, int frame)
{
	static t_animations		exit;
	char					*c;
	int						i;
	static struct timeval	lst;
	struct timeval			now;

	i = 64;
	if (exit.frame == 0)
	{
		while (frame < 12)
		{
			c = combine("textures/exit/", frame + 1, ".xpm");
			exit.exit[frame] = mlx_xpm_file_to_image(params->mlx, c, &i, &i);
			frame++;
		}
	}
	mlx_put_image_to_window(params->mlx, params->win, exit.exit[exit.frame], x
		* TS, y * TS);
	gettimeofday(&now, NULL);
	if (now.tv_sec > lst.tv_sec || (now.tv_sec == lst.tv_sec && now.tv_usec
			- lst.tv_usec > 50000))
	{
		exit.frame = (exit.frame + 1) % 12;
		lst = now;
	}
}

void	draw_coin(t_mlx *params, int x, int y, int frame)
{
	static t_animations		coin;
	char					*c;
	int						i;
	static struct timeval	lst;
	struct timeval			now;

	i = 64;
	if (coin.frame == 0)
	{
		while (frame < 12)
		{
			c = combine("textures/coin/", frame + 1, ".xpm");
			coin.coin[frame] = mlx_xpm_file_to_image(params->mlx, c, &i, &i);
			frame++;
		}
	}
	mlx_put_image_to_window(params->mlx, params->win, coin.coin[coin.frame], x
		* TS, y * TS);
	gettimeofday(&now, NULL);
	if (now.tv_sec > lst.tv_sec || (now.tv_sec == lst.tv_sec && now.tv_usec
			- lst.tv_usec > 50000))
	{
		coin.frame = (coin.frame + 1) % 12;
		lst = now;
	}
}
