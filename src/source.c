/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:19:59 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/21 18:29:33 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_lent(int nb)
{
	int	s;

	if (nb == 0)
	{
		return (1);
	}
	s = 0;
	if (nb < 0)
	{
		s = 1;
	}
	while (nb)
	{
		s++;
		nb = nb / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	unsigned int	i;
	char			*a;
	int				x;

	x = ft_int_lent(n);
	a = malloc((x + 1) * sizeof(char));
	if (!a)
		return (0);
	if (n < 0)
	{
		a[0] = '-';
		i = -n;
	}
	else
	{
		i = n;
	}
	a[x - 1] = '0';
	a[x] = '\0';
	while (i)
	{
		a[--x] = (i % 10) + '0';
		i = i / 10;
	}
	return (a);
}

char	*combine(char *str, int num, char *str2)
{
	char	*n;
	char	*c;

	n = ft_itoa(num);
	c = ft_strjoin(str, n);
	free(n);
	n = ft_strjoin(c, str2);
	free(c);
	return (n);
}
