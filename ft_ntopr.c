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