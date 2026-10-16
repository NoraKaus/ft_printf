/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 11:41:25 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/16 13:24:30 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	int_len(long n);
static void	fill_nums(int i, int len, char *num, long nb);

size_t	ft_itoa(int n)
{
	int		i;
	int		len;
	long	nb;
	char	num[11];

	nb = n;
	len = int_len(nb);
	num[len] = '\0';
	if (nb == 0)
		num[len - 1] = '0';
	i = 0;
	if (n < 0)
	{
		num[0] = '-';
		nb *= -1;
		i++;
	}
	fill_nums(i, len, num, nb);
	write(1, num, len);
	return (len);
}

static void	fill_nums(int i, int len, char *num, long nb)
{
	while (i < len)
	{
		len--;
		num[len] = (nb % 10) + '0';
		nb /= 10;
	}
}

static	int	int_len(long n)
{
	int		len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

// int	main(void)
// {
// 	char *i1 = ft_itoa(-623);
// 	char *i2 = ft_itoa(156);
// 	char *i3 = ft_itoa(-0);
// 	char *i4 = ft_itoa(0);

// 	printf("%s\n", i1);
// 	printf("%s\n", i2);
// 	printf("%s\n", i3);
// 	printf("%s\n", i4);

// 	free(i1);
// 	free(i2);
// 	free(i3);
// 	free(i4);
// }