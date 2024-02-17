/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:50:10 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/18 00:37:52 by btvildia         ###   ########.fr       */
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
# include <unistd.h>

# define TS 64

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

char		**get_map(void);
t_info		numbers_return(char **map);
int			key_hook(int keycode, void **params);
t_textures	get_textures(void *mlx, int last_key);
void		draw_map(void *mlx, void *win, char **map, int last_key);

#endif
