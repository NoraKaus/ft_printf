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

// static unsigned long	int_len(long n, long base_len);
// static unsigned long	print_neg(long *nb, char *num);

ssize_t	ft_ntopr(unsigned long nb, char *base)
{
	unsigned long		base_len;
	unsigned long		len;
	unsigned long		pos;
	char				num[BUFF_SZ];

	pos = BUFF_SZ;
	base_len = ft_strlen(base);
	if (nb == 0)
	{
		pos -= 1;
		num[pos] = '0';
	}
	while (nb > 0)
	{
		pos--;
		num[pos] = base[nb % base_len];
		nb /= base_len;
	}
	len = BUFF_SZ - pos;
	write(1, &num[pos], len);
	return (len);
}

// static unsigned long	print_neg(long *nb, char *num)
// {
// 	if (*nb < 0)
// 	{
// 		num[0] = '-';
// 		*nb *= -1;
// 		return (1);
// 	}
// 	return (0);
// }

// static	unsigned long	int_len(long n, long base_len)
// {
// 	unsigned long	len;

// 	len = 0;
// 	if (n == 0)
// 		len++;
// 	if (n < 0)
// 	{
// 		len++;
// 		n *= -1;
// 	}
// 	while (n > 0)
// 	{
// 		n /= base_len;
// 		len++;
// 	}
// 	return (len);
// }

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