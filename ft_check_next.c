/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:35:56 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/23 18:18:22 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_chck_nxt(va_list *list, t_flags *flags)
{
	ssize_t	no_err;
	ssize_t	total;

	no_err = 0;
	total = 0;
	if (flags->type == 0)
		return (-1);
	sanitize_flags(flags);
	if (flags->type == 'i' || flags->type == 'd' )
		no_err = handle_digits(list, flags);
	else if (flags->type == 'u' || flags->type == 'x' || flags->type == 'X')
		no_err = handle_ul(list, flags, &total);
	else if (flags->type == 'c' || flags->type == 's' || flags->type == '%')
		no_err = handle_text(list, flags);
	else if (flags->type == 'p')
		no_err = handle_pointers(list, &flags);
	return (no_err);
}

static ssize_t	handle_pointers(va_list *list, t_flags *flags)
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
	chk2 = ft_ntopr(ptr, HX_LOW);
	if (chk2 < 0)
		return (-1);
	return (chk1 + chk2);
}

static ssize_t	handle_digits(va_list *list, t_flags *flags)
{
	long			nbr;
	ssize_t			len;
	ssize_t			pos;
	char			num[BUFF_SZ];
	ssize_t			chck;

	nbr = (long)va_arg(*list, int);
	if (nbr < 0)
	{
		flags->negative = 1;
		nbr *= -1;
	}
	len = ft_ntopr((unsigned long)nbr, BASE_TEN, num);
	if (len < 0)
		return (-1);
	pos = BUFF_SZ - len;
	chck = output_num(&num[pos], len, flags);
	if (chck < 0)
		return (-1);
	return (chck + len);
}

static ssize_t	handle_ul(va_list *list, t_flags *flags, ssize_t total)
{
	unsigned long	nbr;
	ssize_t			pos;
	ssize_t			chck;
	char			num[BUFF_SZ];

	nbr = (unsigned long)va_arg(*list, unsigned int);
	if (nbr == 0)
	{
		total = ft_putchar(nbr);
		return (total);
	}
	if (flags->type == 'x')
		total = ft_ntopr(nbr, HX_LOW, num);
	else if (flags->type == 'X')
		total = ft_ntopr(nbr, HX_UP, num);
	else if (flags->type == 'u')
		total = ft_ntopr(nbr, BASE_TEN, num);
	if (total < 0)
		return (-1);
	pos = BUFF_SZ - total;
	chck = output_num(&num[pos], total, flags);
	if (chck < 0)
		return (-1);
	total += chck;
	return (total);
}

static ssize_t	handle_text(va_list *list, t_flags *flags)
{
	ssize_t	prec;
	ssize_t	total;

	prec = get_precision(flags);
	if (flags->type == 's' && prec > 0)
		total = ft_putstr(va_arg(*list, char *), prec);
	else if (flags->type == 's')
		total = ft_putstr(va_arg(*list, char *), -1);
	else
		total = ft_putchar(va_arg(*list, int));
	return (total);
}