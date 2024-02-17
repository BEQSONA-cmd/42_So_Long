/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:50:24 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/18 00:37:58 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*params[3];
	t_info	info;

	info = numbers_return(get_map());
	params[0] = mlx_init();
	params[1] = mlx_new_window(params[0], (info.width - 1) * 64, info.height
			* 64, "Pac_Man");
	params[2] = get_map();
	mlx_key_hook(params[1], key_hook, &params);
	mlx_loop(params[0]);
	free(params[2]);
	return (0);
}
