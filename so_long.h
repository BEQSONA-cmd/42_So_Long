/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:50:10 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/21 23:06:13 by btvildia         ###   ########.fr       */
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

# define WHITE 0xFFFFFF

# define TS 64

typedef struct s_animations
{
	void	*coin[12];
	void	*exit[12];
	void	*up[10];
	void	*down[10];
	void	*left[10];
	void	*right[10];
	int		frame;
}			t_animations;

typedef struct s_info
{
	void	*floor;
	void	*wall;
	int		width;
	int		height;
	int		x;
	int		y;
}			t_info;

int			c_count(char **map);
char		**get_map(char *av);
int			draw_map(void **params);
void		free_window(void **params);
int			*player_position(char **map);
char		*load_pacman_texture(int frame);
t_info		numbers_return(void **params, int i);
int			key_hook(int keycode, void **params);
char		*combine(char *str, int num, char *str2);
void		ft_movement(int keycode, char **map, int x, int y);
void		draw_pacman(void **params, int x, int y, int frame);
void		check_c(int keycode, char **map, int x, int y, int c);
int			exit_check(int keycode, char **map, int x, int y, int c);

#endif
