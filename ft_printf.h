/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:08:39 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/18 19:09:12 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

# define BASE_TEN "0123456789"
# define HX_LOW "0123456789abcdef"
# define HX_UP "0123456789ABCDEF"
# define BUFF_SZ 24

int		ft_printf(const char *input, ...);
ssize_t	display(const char *input, va_list *list);
ssize_t	check_next(const char *input, size_t i, va_list *list);
ssize_t	ft_putchar(int c);
ssize_t	ft_putstr(char *str);
ssize_t	ft_strlen(const char *s);
ssize_t	ft_ntopr(unsigned long nb, char *base);

#endif