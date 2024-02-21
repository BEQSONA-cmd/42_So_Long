/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:50:10 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/18 22:52:33 by btvildia         ###   ########.fr       */
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

# define TS 64

typedef struct s_animations
{
	void	*coin[12];
	void	*exit[12];
	int		frame;
}			t_animations;

typedef struct s_textures
{
	void	*floor;
	void	*wall;
	void	*left;
	void	*right;
	void	*up;
	void	*down;
	void	*img;
}			t_textures;

typedef struct s_info
{
	int		key;
	int		width;
	int		height;
	int		x;
	int		y;
}			t_info;

char		**get_map(char *av);
int			loop_hook(void **params);
t_info		numbers_return(char **map);
int			key_hook(int keycode, void **params);
t_textures	get_textures(void *mlx, int last_key);
void		draw_map(void *mlx, void *win, char **map, int last_key);
t_textures	get_textures(void *mlx, int last_key);
int			combined_hook(int keycode, void **params);
#endif
