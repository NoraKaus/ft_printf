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
	ssize_t	pos;
	ssize_t	zero_pr;
	ssize_t	space_pr;
	char	*prefix;

	prefix = get_prefix(flags);
	pos = BUFF_SZ - len;
	zero_pr = get_precision(flags) - len;
	if (zero_pr < 0)
		zero_pr = 0;
	space_pr = get_width(flags) - (len + zero_pr + ft_strlen(prefix));
	if (flags->minus)
	{
		len += left_aligned(prefix, zero_pr, flags, &num[pos]);
	}
	else
		len += right_aligned(prefix, zero_pr, flags, &num[pos]);

}

ssize_t	left_aligned(char *prefix, ssize_t zero_pr, t_flags *flags, char *num)
{
	ssize_t	chck;
	ssize_t	total;

	if (flags->negative)
	{
		chck = write(1, '-', 1);
		if (chck < 0)
			return (-1);
		total += chck;
	}
	chck = ft_putstr(prefix, ft_strlen(prefix));
	if (chck < 0)
		return (-1);
	total += chck;
	chck = put_loop(zero_pr, '0');
	if (chck < 0)
		return (-1);
	total += chck;
	chck = ft_pustr(num, ft_strlen(num));
	if (chck < 0)
		return (-1);
	return (total + chck);
}

ssize_t	right_aligned(char *prefix, ssize_t zero_pr, t_flags *flags, char *num)
{
	ssize_t	chck;
	ssize_t	total;

	if (flags->negative)
	{
		chck = write(1, '-', 1);
		if (chck < 0)
			return (-1);
		total += chck;
	}
	chck = ft_putstr(prefix, ft_strlen(prefix));
	if (chck < 0)
		return (-1);
	total += chck;
	chck = put_loop(zero_pr, '0');
	if (chck < 0)
		return (-1);
	total += chck;
	chck = ft_pustr(num, ft_strlen(num));
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