/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:18:05 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/15 20:29:46 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <string.h>

#define RED 0xFF0000

#define TILE_SIZE 64 // Size of each tile in pixelsa
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

char	*map[] = {"1111111111111", "1001000000001", "1000011111001",
		"1000110000001", "1111111111111"};

void	draw_map(void *mlx, void *win)
{
	for (unsigned long y = 0; y < sizeof(map) / sizeof(map[0]); y++)
	{
		for (unsigned long x = 0; x < strlen(map[0]); x++)
		{
			if (map[y][x] == '1')
			{
				mlx_pixel_put(mlx, win, x * TILE_SIZE, y * TILE_SIZE, 0xFFFFFF);
				// Draw white pixel for '1'
			}
			else
			{
				mlx_pixel_put(mlx, win, x * TILE_SIZE, y * TILE_SIZE, RED);
				// Draw black pixel for '0'
			}
		}
	}
}

int	key_hook(int keycode, void *param)
{
	if (keycode == 53) // 53 is the keycode for the "esc" key
	{
		mlx_destroy_window(((void **)param)[0], ((void **)param)[1]);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*params[2] = {mlx, mlx_win};

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	mlx_key_hook(mlx_win, key_hook, params);
	draw_map(mlx, mlx_win);
	mlx_loop(mlx);
	return (0);
}
