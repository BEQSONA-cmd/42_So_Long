/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:55:19 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/21 17:21:59 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define RED "\x1b[31m"
# define BLUE "\x1b[34m"
# define RESET "\x1b[0m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define PURPLE "\x1b[35m"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_itoa(int n);
int		ft_strlen(char *c);
char	*get_next_line(int fd);
char	*ft_nline(char *s, int c);
char	*ft_strjoin_null(char *s2);
int		ft_find_char(int c, int i);
int		ft_find_str(char *a, int i);
int		ft_find_number(int n, int i);
int		ft_printf(const char *a, ...);
int		ft_strcmp(char *s1, char *s2);
int		ft_find_hexup(size_t n, int i);
int		ft_ptr(unsigned long nb, int j);
char	*ft_strjoin(char *s1, char *s2);
int		ft_find_hexlow(size_t n, int i);
char	*ft_reallocate(char *s1, char *s2);
int		ft_find_uns(unsigned int n, int i);
int		ft_find_ptr(unsigned long ptr, int j);
int		ft_next_precent(const char *format, va_list args, int j, int i);

#endif
