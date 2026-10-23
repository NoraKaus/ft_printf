/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:08:04 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/23 13:05:28 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"


ssize_t	sanitize_flags(t_flags *flags)
{
	if (flags->minus || flags->type == 's' || flags->type == 'c')
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
	if (flags->precision != -1)
		flags->zero = 0;
	if (flags->type == 'x' || flags->type == 'X' || flags->type == 'u'
		|| flags->type == 's' || flags->type == 'c')
	{
		flags->plus = 0;
		flags->space = 0;
	}
	if (flags->type == 'p')
	{
		flags->zero = 0;
		flags->precision = -1;
	}
	if (flags->type != 'x' || flags->type != 'X')
		flags->hash = 0;
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
	{
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
	if (flags->hash && flags->type == 'X')
		return ("0X");
	else if (flags->hash && flags->type == 'x')
		return ("0x");
	return ("");
}