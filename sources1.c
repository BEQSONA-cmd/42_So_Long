/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:08:39 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/26 14:50:28 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	i = 489;
	j = 258;
	loose = mlx_xpm_file_to_image(p->mlx, "./textures/you_loose.xpm", &i, &j);
	mlx_put_image_to_window(p->mlx, p->win, loose, (x * TS) / 2 - i / 2, (y
			* TS) / 2 - j / 2);
	return (0);
}

t_numbers	get_numbers(t_mlx *p)
{
	t_numbers	nums;
	int			i;

	i = 64;
	nums.zero = mlx_xpm_file_to_image(p->mlx, "./textures/nums/0.xpm", &i, &i);
	nums.one = mlx_xpm_file_to_image(p->mlx, "./textures/nums/1.xpm", &i, &i);
	nums.two = mlx_xpm_file_to_image(p->mlx, "./textures/nums/2.xpm", &i, &i);
	nums.three = mlx_xpm_file_to_image(p->mlx, "./textures/nums/3.xpm", &i, &i);
	nums.four = mlx_xpm_file_to_image(p->mlx, "./textures/nums/4.xpm", &i, &i);
	nums.five = mlx_xpm_file_to_image(p->mlx, "./textures/nums/5.xpm", &i, &i);
	nums.six = mlx_xpm_file_to_image(p->mlx, "./textures/nums/6.xpm", &i, &i);
	nums.seven = mlx_xpm_file_to_image(p->mlx, "./textures/nums/7.xpm", &i, &i);
	nums.eight = mlx_xpm_file_to_image(p->mlx, "./textures/nums/8.xpm", &i, &i);
	nums.nine = mlx_xpm_file_to_image(p->mlx, "./textures/nums/9.xpm", &i, &i);
	return (nums);
}

void	display_digit(t_mlx *p, int digit, int x, int y, t_numbers nums)
{
	void	*digitImages[] = {nums.zero, nums.one, nums.two, nums.three,
			nums.four, nums.five, nums.six, nums.seven, nums.eight, nums.nine};
	if (digit >= 0 && digit <= 9)
	{
		mlx_put_image_to_window(p->mlx, p->win, digitImages[digit], x, y);
	}
}

int	count_digits(int num)
{
	return (num == 0 ? 1 : (int)(log10(num) + 1));
}

void	draw_coin_count(t_mlx *p, int c, int width, int height)
{
	t_numbers	nums;
	int			num_digits;
	int			x;
	int  k = 64;
	int			y;
	int			digit;
	int			i;

	i = 440;
	nums = get_numbers(p);
	num_digits = count_digits(c);
	nums.coins = mlx_xpm_file_to_image(p->mlx, "./textures/coins.xpm", &k, &k);
	if (num_digits == 1)
		i = 320;
	x = (width + i) - num_digits * 64;
	y = (64 * (height + 1)) - 64;
	if (c == 0)
	{
		mlx_put_image_to_window(p->mlx, p->win, nums.coins, width / 2, y);
		display_digit(p, 0, x, y, nums);
		return ;
	}
	while (c > 0)
	{
		digit = c % 10;
		mlx_put_image_to_window(p->mlx, p->win, nums.coins, width / 2, y);
		display_digit(p, digit, x, y, nums);
		c = c / 10;
		x = x - 64;
	}
}

int	draw_map(t_mlx *p)
{
	int			y;
	int			x;
	t_info		info;
	char		**map;
	static int	previous_c = -1;

	map = p->map;
	info = numbers_return(*p, 0);
	y = 0;
	if (previous_c == -1)
	{
		previous_c = c_count(map);
	}
	while (y < info.height)
	{
		x = 0;
		while (x < info.width)
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(p->mlx, p->win, info.floor, x * TS, y
					* TS);
			else if (map[y][x] == '0')
				mlx_put_image_to_window(p->mlx, p->win, info.wall, x * TS, y
					* TS);
			else if (map[y][x] == 'P')
				draw_pacman(p, x, y, 0);
			else if (map[y][x] == 'C')
				draw_coin(p, x, y, 0);
			else if (map[y][x] == 'E')
				draw_exit(p, x, y, 0);
			else if (map[y][x] == 'S')
				draw_enemy(p, x, y, 0);
			x++;
		}
		y++;
	}
	draw_coin_count(p, c_count_from_zero(map, &previous_c), info.width,
		info.height);
	
	p->frame++;
	if(p->frame >= 40){
		
		const int i = point_return(map, p->temp_j);
		p->temp_j = ft_enemy_movement(i, map, info.enemy_x, info.enemy_y);
		p->frame = 0;
		if (p->temp_j == 15)
			mlx_loop_hook(p->mlx, draw_loose, (void *)p);
	}
	return (0);
}

int	exit_check(int keycode, char **map, int x, int y, int c)
{
	if (keycode == W && map[y - 1][x] == 'E' && c == 0)
	{
		ft_move(map, x, y, 1);
		return (1);
	}
	else if (keycode == S && map[y + 1][x] == 'E' && c == 0)
	{
		ft_move(map, x, y, 2);
		return (1);
	}
	else if (keycode == A && map[y][x - 1] == 'E' && c == 0)
	{
		ft_move(map, x, y, 3);
		return (1);
	}
	else if (keycode == D && map[y][x + 1] == 'E' && c == 0)
	{
		ft_move(map, x, y, 4);
		return (1);
	}
	return (0);
}

void	check_c(int keycode, char **map, int x, int y, int c)
{
	static int	i;

	if (keycode == W && map[y - 1][x] == 'C')
	{
		i++;
		printf("%d/%d\n", c + i - 1, i);
	}
	else if (keycode == S && map[y + 1][x] == 'C')
	{
		i++;
		printf("%d/%d\n", c + i - 1, i);
	}
	else if (keycode == A && map[y][x - 1] == 'C')
	{
		i++;
		printf("%d/%d\n", c + i - 1, i);
	}
	else if (keycode == D && map[y][x + 1] == 'C')
	{
		i++;
		printf("%d/%d\n", c + i - 1, i);
	}
}
