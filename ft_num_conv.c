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

	pos = BUFF_SZ;
	num[pos] = '\0';
	pos--;
	base_len = ft_strlen(base);
	if (nb == 0)
	{
		pos -= 1;
		num[pos] = base[0];
	}
	while (nb > 0)
	{
		pos--;
		num[pos] = base[nb % base_len];
		nb /= base_len;
	}
	len = BUFF_SZ - pos;
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
	space_pr = get_width(flags) - (len + zero_pr + ft_strlen(prefix) - 1);
	if (flags->minus && !flags->zero)
		chck = left_al(prefix, zero_pr, space_pr, num);
	else if (flags->minus && flags->zero && flags->precision >= 0)
		chck = left_al(prefix, zero_pr, space_pr, num);
	else if
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
	chck = put_loop(space_pr, ' ');
	if (chck < 0)
		return (-1);
	return (total + chck);
}

// int	main(void)
// {
// 	ft_ntopr(-623, BASE_TEN);
// 	write (1, "\n", 1);
// 	ft_ntopr(156, BASE_TEN);
// 	write (1, "\n", 1);
// 	ft_ntopr(-0, HX_LOW);
// 	write (1, "\n", 1);
// 	ft_ntopr(0, HX_UP);
// }