/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_puts_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:07:29 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/23 14:33:08 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

ssize_t	ft_putchar(int c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

ssize_t	ft_putstr(char *str, ssize_t len)
{
	if (len == -1)
		len = ft_strlen(str);
	if (!str)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	if (write(1, str, len) < 0)
		return (-1);
	return (len);
}

ssize_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

ssize_t	put_loop(ssize_t len, char s)
{
	ssize_t	err;
	ssize_t	count;

	err = -1;
	count = 0;
	while (0 < len)
	{
		err = write(1, &s, 1);
		if (err < 0)
			return (-1);
		len--;
		count++;
	}
	return (count);
}
