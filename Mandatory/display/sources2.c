/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:43:30 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/04 16:45:45 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		ft_error();
	return (ptr);
}

int	exit_game(void)
{
	exit(0);
	return (0);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
