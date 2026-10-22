/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_puts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 15:43:57 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/22 16:28:18 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putchar(int c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

ssize_t	ft_putstr(char *str)
{
	size_t	len;


	if (!str)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	len = ft_strlen(str);
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