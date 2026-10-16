/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:57:49 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/16 17:54:00 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *input, ...);
size_t	ft_putchar(int c);
size_t	ft_putstr(char *str);
size_t	ft_itoa(int n);
size_t	ft_strlen(const char *s);
size_t	display(const char *input, va_list list);
size_t	check_next(const char *input, size_t i, va_list list, size_t *total);



#endif