/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:50:10 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/26 22:07:36 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "src/ft_printf.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define TS 64

typedef struct s_position
{
	int		*x;
	int		*y;
	int		count;
}			t_position;

typedef struct s_numbers
{
	void	*moves;
	void	*coins;
	void	*digits[10];
}			t_numbers;

typedef struct s_animations
{
	void	*coin[12];
	void	*exit[12];
	void	*up[10];
	void	*down[10];
	void	*left[10];
	void	*right[10];
	void	*gost_right[8];
	void	*gost_left[8];
	int		frame;
}			t_animations;

typedef struct s_info
{
	void	*floor;
	void	*wall;
	void	*loose;
	int		width;
	int		height;
	int		x;
	int		y;
	int		enemy_x;
	int		enemy_y;
}			t_info;

typedef struct s_mlx
{
	int		keycode;
	int		key;
	void	*mlx;
	void	*win;
	char	**map;
	int		frame;
	int		*temp_j;
	int		moves;
}			t_mlx;

int			draw_win(t_mlx *p);
char		**get_map(char *av);
void		check_map(char **c);
int			c_count(char **map);
void		check_ones(char **c);
int			draw_loose(t_mlx *p);
t_numbers	get_numbers(t_mlx *p);
void		check_square(char **c);
int			draw_everything(t_mlx *p);
void		free_window(t_mlx params);
int			*enemy_position(char **map);
t_position	enemys_positioon(char **map);
int			*player_position(char **map);
void		check_double(char **c, char a);
int			*point_return(char **map, int *j);
t_info		numbers_return(t_mlx params, int i);
int			key_hook(int keycode, t_mlx *params);
int			from_zero(char **map, int *previous_c);
char		*load_enemy_texture(int frame, int key);
char		*combine(char *str, int num, char *str2);
void		ft_move(char **map, int x, int y, int dir);
void		draw_moves(t_mlx *p, int width, int height);
char		*load_pacman_texture(int frame, int keycode);
int			enemy_move(char **map, int x, int y, int num);
int			ft_find_one(int point, char **map, int x, int y);
int			exit_check(int keycode, char **map, int x, int y);
void		draw_exit(t_mlx *params, int x, int y, int frame);
void		draw_coin(t_mlx *params, int x, int y, int frame);
void		draw_enemy(t_mlx *params, int x, int y, int frame);
void		draw_map(t_mlx *p, char **map, t_info info, int y);
int			ft_movement(int keycode, char **map, int x, int y);
void		draw_pacman(t_mlx *params, int x, int y, int frame);
void		draw_coin_count(t_mlx *p, int c, int width, int height);
int			*ft_enemy_movement(const int *point, char **map, int *x, int *y);

#endif
