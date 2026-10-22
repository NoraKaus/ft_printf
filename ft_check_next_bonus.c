/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_next_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:35:56 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/22 17:23:51 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

ssize_t	ft_chck_nxt(va_list *list, t_flags *flags)
{
	ssize_t				no_err;

	no_err = 0;
	if (flags->type == 0)
		return (-1);
	if (flags->type == 'i' || flags->type == 'd' )
		no_err = handle_digits(list, flags);
	else if (flags->type == 'u' || flags->type == 'x' || flags->type == 'X')
		no_err = handle_ul(list, flags);
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
	char			num[BUFF_SZ];
	ssize_t			chk;

	nbr = (long)va_arg(*list, int);
	if (nbr < 0)
	{
		flags->negative = 1;
		nbr *= -1;
	}
	len = ft_ntopr((unsigned long)nbr, BASE_TEN, num);
	if (len < 0)
		return (-1);
	output_num(num, len, flags);

}

static ssize_t	handle_ul(va_list *list, t_flags *flags)
{
	unsigned long	nbr;
	ssize_t			len;
	char 			*prefix = NULL;
	char			num[BUFF_SZ];

	nbr = (unsigned long)va_arg(*list, unsigned int);

	if (flags->type == 'x')
		prefix = get_prefix(flags);


}

static ssize_t	handle_text(va_list *list, t_flags *flags)
{
	ssize_t prec;
	ssize_t total;

	prec = get_precision(flags);
	if (flags->type == 's' && prec > 0)
	{
		
	}
	

}

void	output_num(char *num, ssize_t len, t_flags *flags)
{
	ssize_t	pos;
	ssize_t zero_pr;
	ssize_t all_no_padding;
	ssize_t space_pr;
	char 	*prefix;

	prefix = get_prefix(flags);
	pos = BUFF_SZ - len;
	zero_pr = get_precision(flags) - len;
	if (zero_pr < 0)
		zero_pr = 0;
	all_no_padding = len + zero_pr + ft_strlen(prefix);
	space_pr = get_width(flags) - all_no_padding;

}

ssize_t	get_width(t_flags *flags)
{
	ssize_t	width;

	if (flags->width)
	{
		width = flags->width;
		return (width);
	}
	return (0);
}

ssize_t	get_precision(t_flags *flags)
{
	ssize_t	prec;

	if (flags->precision)
	{char 	*prefix;
		prec = flags->precision;
		return (prec);
	}
	return (0);
}

char	*get_prefix(t_flags *flags)
{
	if (flags->negative)
		return ("-");
	else if (flags->plus)
		return ("+");
	else if (flags->space)
		return (" ");
	else if (flags->hash && flags->type == 'X')
		return ("0X");
	else if (flags->hash && flags->type == 'x')
		return ("0x");
	return("");
}