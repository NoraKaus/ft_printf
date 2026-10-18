/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:57:58 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/16 17:57:32 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list	list;
	size_t	ttl_print;

	va_start(list, input);
	ttl_print = display(input, list);
	va_end(list);
	return (ttl_print);
}

size_t	display(const char *input, va_list list)
{
	size_t			i;
	size_t			*total;

	i = 0;
	while (input[i])
	{
		if (input[i] != '%')
			*total += ft_putchar(input[i]);
		else
			i = check_next(input, i + 1, list, total);
		i++;
	}
	return (*total);
}

size_t	check_next(const char *input, size_t i, va_list list, size_t *total)
{
	if (input[i] == 'i' || input[i + 1] == 'd')
		*total += ft_itoa(va_arg(list, unsigned long));
	else if (input[i] == 'c')
		*total += ft_putchar(va_arg(list, unsigned long));
	else if (input[i] == 's')
		*total += ft_putstr(va_arg(list, char *));
	return (i);
}

// int main(void)
// {
// 	int n = 123;
// 	int c = 'r';

// 	ft_printf("Hello %i %c", n, c);
// }

// %c Prints a single character.
// %s Prints a string (as defined by the common C convention).
// %p The void * pointer argument has to be printed in hexadecimal format.
// %d Prints a decimal (base 10) number.
// %i Prints an integer in base 10.
// %u Prints an unsigned decimal (base 10) number.
// %x Prints a number in hexadecimal (base 16) lowercase format.
// %X Prints a number in hexadecimal (base 16) uppercase format.
// %% Prints a percent sig


