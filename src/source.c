/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:19:59 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/01 12:43:50 by btvildia         ###   ########.fr       */
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

char	*combines(char *s1, char *s2, char *s3)
{
	char	*a;
	char	*c;

	a = ft_strjoin(s1, s2);
	c = ft_strjoin(a, s3);
	free(a);
	return (c);
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (1);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
