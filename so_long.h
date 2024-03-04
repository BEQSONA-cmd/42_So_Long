/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:50:10 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/04 16:41:58 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "src/ft_printf.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define MAP_SIZE 100
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define TS 64

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

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
	void	*pacman[10];
	void	*gost[8];
	int		frame;
}			t_animations;

typedef struct s_info
{
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
	char	*level;
}			t_mlx;

typedef struct s_texture
{
	void	*pac;
	void	*coin;
	void	*exit;
	void	*you_win;
}			t_texture;

void		ft_error(void);
int			exit_game(void);
int			e_find(char **map);
int			draw_win(t_mlx *p);
char		**get_map(char *av);
void		check_map(char **c);
int			c_count(char **map);
void		free_map(char **map);
void		check_ones(char **c);
int			draw_loose(t_mlx *p);
int			map_width(char **map);
t_numbers	get_numbers(t_mlx *p);
t_mlx		*get_param(char *av[]);
int			map_height(char **map);
void		check_square(char **c);
void		*ft_malloc(size_t size);
int			check_level(char *level);
void		free_window(t_mlx params);
int			draw_everything(t_mlx *p);
void		draw_everything_2(t_mlx *p);
t_position	enemys_positioon(char **map);
void		check_double(char **c, char a);
int			*point_return(char **map, int *j);
int			if_equals(int j, int e_x, int p_x);
int			draw_map_all(t_mlx *p, t_texture t);
t_info		numbers_return(t_mlx params, int i);
int			key_hook(int keycode, t_mlx *params);
void		check_valid(char **map, int x, int y);
int			from_zero(char **map, int *previous_c);
void		check_ac(t_mlx *par, int ac, char **av);
char		*load_enemy_texture(int frame, int key);
char		*combine(char *str, int num, char *str2);
void		ft_move(char **map, int x, int y, int dir);
void		draw_moves(t_mlx *p, int width, int height);
void		draw_enemys(t_mlx *p, char **map, int level);
char		*load_pacman_texture(int frame, int keycode);
int			enemy_move(char **map, int x, int y, int num);
int			player_position(char **map, char c, int which);
int			get_x_position(int moves, int width, int which);
void		put_coin_images(t_mlx *p, int x, t_numbers nums);
int			ft_find_one(int point, char **map, int x, int y);
int			exit_check(int keycode, char **map, int x, int y);
void		draw_exit(t_mlx *params, int x, int y, int frame);
void		draw_coin(t_mlx *params, int x, int y, int frame);
void		draw_enemy(t_mlx *params, int x, int y, int frame);
int			ft_movement(int keycode, char **map, int x, int y);
void		draw_pacman(t_mlx *params, int x, int y, int frame);
int			draw_map(t_mlx *p, int height, int width, char **map);
void		put_image(t_mlx *p, int w, int height, t_numbers nums);
void		draw_wall_floor(t_mlx *p, int height, int width, int y);
void		put_frames(t_mlx *p, int w, int height, t_numbers nums);
void		draw_coin_count(t_mlx *p, int c, int width, int height);
void		destroy_frame(t_mlx *params, t_animations *gost, int frame);
void		put_coin_frames(t_mlx *p, int c, t_numbers nums, int digit);
void		destroy_frame_2(t_mlx *params, t_animations *gost, int which);
void		update_frame(t_animations *gost, struct timeval *lst, int speed,
				int frame);
int			*ft_enemy_movement(const int *point, char **map, t_position posi);

#endif
