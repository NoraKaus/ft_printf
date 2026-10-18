/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:57:49 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/18 18:16:52 by ekausiny         ###   ########.fr       */
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


int		ft_printf(const char *input, ...);
ssize_t	display(const char *input, va_list *list);
ssize_t	check_next(const char *input, size_t i, va_list *list);
ssize_t	ft_putchar(int c);
ssize_t	ft_putstr(char *str);
ssize_t	ft_strlen(const char *s);
ssize_t	ft_ntopr(unsigned long nb, char *base);

#endif