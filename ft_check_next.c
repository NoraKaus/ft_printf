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

static ssize_t	handle_pointers(va_list *list, t_flags *flags);
static ssize_t	handle_digits(va_list *list, t_flags *flags);
static ssize_t	handle_ul(va_list *list, t_flags *flags);
static ssize_t	handle_text(va_list *list, t_flags *flags);

ssize_t	ft_chck_nxt(va_list *list, t_flags *flags)
{
	ssize_t	no_err;

	no_err = 0;
	if (flags->type == 0)
		return (-1);
	sanitize_flags(flags);
	if (flags->type == 'i' || flags->type == 'd' )
		no_err = handle_digits(list, flags);
	else if (flags->type == 'u' || flags->type == 'x' || flags->type == 'X')
		no_err = handle_ul(list, flags);
	else if (flags->type == 'c' || flags->type == 's' || flags->type == '%')
		no_err = handle_text(list, flags);
	else if (flags->type == 'p')
		no_err = handle_pointers(list, flags);
	return (no_err);
}

static ssize_t	handle_pointers(va_list *list, t_flags *flags)
{
	unsigned long	ptr;
	ssize_t			len1;
	ssize_t			len2;
	ssize_t			pos;
	char			num[BUFF_SZ];

	ptr = (unsigned long)va_arg(*list, unsigned long);
	if (!ptr)
		return (write(1, "(nil)", 5));
	len1 = ft_ntopr(ptr, HX_LOW, num);
	if (len1 < 0)
		return (-1);
	pos = BUFF_SZ - len1;
	len2 = output_num(&num[pos], len1, flags);
	if (len2 < 0)
		return (-1);
	return (len2);
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
	return (chck);
}

static ssize_t	handle_ul(va_list *list, t_flags *flags)
{
	unsigned long	nbr;
	ssize_t			pos;
	ssize_t			chck;
	ssize_t			len;
	char			num[BUFF_SZ];

	nbr = (unsigned long)va_arg(*list, unsigned int);
	if (flags->type == 'x')
		len = ft_ntopr(nbr, HX_LOW, num);
	else if (flags->type == 'X')
		len = ft_ntopr(nbr, HX_UP, num);
	else if (flags->type == 'u')
		len = ft_ntopr(nbr, BASE_TEN, num);
	if (len < 0)
		return (-1);
	pos = BUFF_SZ - len;
	chck = output_num(&num[pos], len, flags);
	if (chck < 0)
		return (-1);
	return (chck);
}

static ssize_t	handle_text(va_list *list, t_flags *flags)
{
	ssize_t	prec;
	ssize_t	total;

	total = -1;
	prec = get_precision(flags);
	if (flags->type == 's' && prec > 0)
		total = ft_putstr(va_arg(*list, char *), prec);
	else if (flags->type == 's')
		total = ft_putstr(va_arg(*list, char *), -1);
	else if (flags->type == 'c')
		total = ft_putchar(va_arg(*list, int));
	else if (flags->type == '%')
		total = ft_putchar('%');
	return (total);
}
