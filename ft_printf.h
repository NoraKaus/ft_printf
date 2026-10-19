/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:08:39 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/19 14:33:52 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define BASE_TEN "0123456789"
# define HX_LOW "0123456789abcdef"
# define HX_UP "0123456789ABCDEF"
# define BUFF_SZ 24

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	plus;
	int	space;
	int	hash;
	int	width;
	int	width_len;
	int	precision;
	int	precision_len;
}	t_flags;

int		ft_printf(const char *input, ...);
ssize_t	display(const char *input, va_list *list);
ssize_t	check_next(const char *input, size_t i, va_list *list);
ssize_t	ft_putchar(int c);
ssize_t	ft_putstr(char *str);
ssize_t	ft_strlen(const char *s);
ssize_t	ft_ntopr(unsigned long nb, char *base);

#endif