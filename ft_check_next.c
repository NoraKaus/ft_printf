/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:35:56 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/20 15:53:14 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	handle_pointers(va_list *list, char inp);
static ssize_t	handle_negatives(va_list *list);

ssize_t	ft_chck_nxt(const char *input, size_t i, va_list *list, t_flags *flags)
{
	ssize_t	no_err;

	no_err = 0;
	if (input[i] == 'i' || input[i] == 'd' )
		no_err = handle_negatives(list);
	else if (input[i] == 'u')
		no_err = ft_ntopr((unsigned long)va_arg(*list, unsigned int), BASE_TEN,\
		flags, input[i]);
	else if (input[i] == 'c')
		no_err = ft_putchar(va_arg(*list, int));
	else if (input[i] == 's')
		no_err = ft_putstr(va_arg(*list, char *));
	else if (input[i] == 'x')
		no_err = ft_ntopr((unsigned long)va_arg(*list, unsigned int), HX_LOW,\
		flags, input[i]);
	else if (input[i] == 'X')
		no_err = ft_ntopr((unsigned long)va_arg(*list, unsigned int), HX_UP,\
		flags, input[i]);
	else if (input[i] == 'p')
		no_err = handle_pointers(list, input[i]);
	else if (input[i] == '%')
		no_err = write(1, &input[i], 1);
	return (no_err);
}

static ssize_t	handle_pointers(va_list *list, char inp)
{
	unsigned long	ptr;
	ssize_t			chk1;
	ssize_t			chk2;

	ptr = (unsigned long)va_arg(*list, unsigned long);
	if (!ptr)
		return (write(1, "(nil)", 5));
	chk1 = write (1, "0x", 2);
	if (chk1 < 0)
		return (-1);
	chk2 = ft_ntopr(ptr, HX_LOW, inp);
	if (chk2 < 0)
		return (-1);
	return (chk1 + chk2);
}

static ssize_t	handle_negatives(va_list *list)
{
	long			nbr;
	ssize_t			ch1;
	ssize_t			ch2;

	ch1 = 0;
	nbr = (long)va_arg(*list, int);
	if (nbr < 0)
	{
		ch1 = write (1, "-", 1);
		if (ch1 < 0)
			return (-1);
		nbr *= -1;
	}
	ch2 = ft_ntopr((unsigned long)nbr, BASE_TEN);
	if (ch2 < 0)
		return (-1);
	return (ch1 + ch2);
}