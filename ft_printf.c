/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:57:58 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/23 18:18:13 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list	list;
	ssize_t	ttl_print;

	va_start(list, input);
	ttl_print = display(input, &list);
	va_end(list);
	if (ttl_print < 0)
		return (-1);
	return (ttl_print);
}

ssize_t	display(const char *input, va_list *list)
{
	ssize_t			i;
	ssize_t			total;
	ssize_t			output;

	i = 0;
	output = 0;
	total = 0;
	while (input[i++])
	{
		if (input[i] != '%')
			output = write(1, &input[i], 1);
		else
		{
			if (input[i + 1] == '\0')
				return (total);
			output = handle_output(input, i + 1, list);
			i++;
		}
		if (output < 0)
			return (-1);
		total += output;
	}
	return (total);
}

ssize_t	handle_output(const char *input, ssize_t *i, va_list *list)
{
	t_flags	flags;
	ssize_t	count;

	count = 0;
	init_struct(&flags);
	t_parsef(input, i, &flags);
	count = ft_chck_nxt(list, &flags);
	if (count < 0)
		return (-1);
	return (count);
}


