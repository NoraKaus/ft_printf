/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 11:41:25 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/18 15:17:43 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_ntopr(unsigned long nb, char *base, char	*num)
{
	unsigned long		base_len;
	unsigned long		len;
	unsigned long		pos;

	pos = BUFF_SZ - 1;
	num[pos] = '\0';
	pos -= 1;
	base_len = ft_strlen(base);
	if (nb == 0)
	{
		num[pos] = base[0];
		pos--;
	}
	while (nb > 0)
	{
		num[pos] = base[nb % base_len];
		nb /= base_len;
		pos--;
	}
	len = BUFF_SZ - 2 - pos;
	return (len);
}

ssize_t	output_num(char *num, ssize_t len, t_flags *flags)
{
	ssize_t	zero_pr;
	ssize_t	space_pr;
	ssize_t	chck;
	char	*prefix;

	prefix = get_prefix(flags);
	zero_pr = get_precision(flags) - len;
	if (zero_pr < 0)
		zero_pr = 0;
	space_pr = get_width(flags) - (len + zero_pr + ft_strlen(prefix));
	if (flags->minus)
		chck = left_al(prefix, zero_pr, space_pr, num);
	else if (flags->zero && flags->precision == -1)
	{
		zero_pr = space_pr;
		space_pr = 0;
		chck = zero_right(prefix, zero_pr, space_pr, num);
	}
	else
		chck = right_al(prefix, zero_pr, space_pr, num);
	if (chck < 0)
		return (-1);
	return (chck);
}

ssize_t	left_al(char *prefix, ssize_t zero_pr, ssize_t space_pr, char *num)
{
	ssize_t	chck;
	ssize_t	total;

	total = 0;
	chck = ft_putstr(prefix, ft_strlen(prefix));
	if (chck < 0)
		return (-1);
	total += chck;
	chck = put_loop(zero_pr, '0');
	if (chck < 0)
		return (-1);
	total += chck;
	chck = ft_putstr(num, ft_strlen(num));
	if (chck < 0)
		return (-1);
	total += chck;
	chck = put_loop(space_pr, ' ');
	if (chck < 0)
		return (-1);
	return (total + chck);
}

ssize_t	right_al(char *prefix, ssize_t zero_pr, ssize_t space_pr, char *num)
{
	ssize_t	chck;
	ssize_t	total;

	total = 0;
	if (add_pad(space_pr, ' ', &total) < 0)
		return (-1);
	chck = ft_putstr(prefix, ft_strlen(prefix));
	if (chck < 0)
		return (-1);
	total += chck;
	if (add_pad(zero_pr, '0', &total) < 0)
		return (-1);
	chck = ft_putstr(num, ft_strlen(num));
	if (chck < 0)
		return (-1);
	return (total + chck);
}

ssize_t	zero_right(char *prefix, ssize_t zero_pr, ssize_t space_pr, char *num)
{
	ssize_t	chck;
	ssize_t	total;

	total = 0;
	chck = ft_putstr(prefix, ft_strlen(prefix));
	if (chck < 0)
		return (-1);
	total += chck;
	if (add_pad(space_pr, ' ', &total) < 0)
		return (-1);
	if (add_pad(zero_pr, '0', &total) < 0)
		return (-1);
	chck = ft_putstr(num, ft_strlen(num));
	if (chck < 0)
		return (-1);
	return (total + chck);
}
