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

unsigned long	ft_out_fl(t_flags *flags, unsigned long len, unsigned long pos,\
	char inp);

ssize_t	ft_ntopr(unsigned long nb, char *base, t_flags *flags, char inp)
{
	unsigned long		base_len;
	unsigned long		len;
	unsigned long		pos;
	unsigned long		fl_chars;
	char				num[BUFF_SZ];

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
	fl_chars = ft_pr_flags(flags, len, pos, inp);
	if (write(1, &num[pos], len) < 0)
		return (-1);
	free (flags);
	return (ft_chars + len);
}

unsigned long	ft_out_fl(t_flags *flags, unsigned long len, unsigned long pos,\
	char inp)
{
	unsigned long	ttl;

	if (inp == 'x' && flags->hash)
		ttl = write (1, "0x", 2);
	if (inp == 'X' && flags->hash)
		ttl = write (1, "0X", 2);
	if (inp == 'i' || inp == 'd' && inp == '+')


}

void put_symbol(char inp, char s)
{
	char s;

	s = 0;
	if (s = '+')
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