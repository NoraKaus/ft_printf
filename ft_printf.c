/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:57:58 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/18 18:19:37 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	handle_pointers(va_list *list);

int	ft_printf(const char *input, ...)
{
	va_list	list;
	ssize_t	ttl_print;

	va_start(list, input);
	ttl_print = display(input, &list);
	if (ttl_print < 0)
		return (-1);
	va_end(list);
	return (ttl_print);
}

ssize_t	display(const char *input, va_list *list)
{
	ssize_t			i;
	ssize_t			total;
	int				output;

	i = 0;
	output = 0;
	total = 0;
	while (input[i])
	{
		if (input[i] != '%')
			output = write(1, &input[i], 1);
		else
		{
			if (input[i + 1] == '\0')
				return (total);
			output = check_next(input, i + 1, list);
			i++;
		}
		if (output < 0)
			return (-1);
		total += output;
		i++;
	}
	return (total);
}

ssize_t	check_next(const char *input, size_t i, va_list *list)
{
	ssize_t	no_err;

	no_err = 0;
	if (input[i] == 'i' || input[i] == 'd' )
		no_err = ft_ntopr((long)va_arg(*list, int), BASE_TEN);
	else if (input[i] == 'u')
		no_err = ft_ntopr((unsigned long)va_arg(*list, unsigned int), BASE_TEN);
	else if (input[i] == 'c')
		no_err = ft_putchar(va_arg(*list, int));
	else if (input[i] == 's')
		no_err = ft_putstr(va_arg(*list, char *));
	else if (input[i] == 'x')
		no_err = ft_ntopr((unsigned long)va_arg(*list, unsigned int), HX_LOW);
	else if (input[i] == 'X')
		no_err = ft_ntopr((unsigned long)va_arg(*list, unsigned int), HX_UP);
	else if (input[i] == 'p')
		no_err = handle_pointers(list);
	else if (input[i] == '%')
		no_err = write(1, &input[i], 1);
	return (no_err);
}

static ssize_t	handle_pointers(va_list *list)
{
	unsigned long	ptr;
	ssize_t			chk1;
	ssize_t			chk2;

	ptr = va_arg(*list, unsigned long);
	if (!ptr)
		return (write(1, "(nil)", 5));
	chk1 = write (1, "0x", 2);
	chk2 = ft_ntopr(ptr, HX_LOW);
	if ((chk1 < 0) || (chk2 < 0))
		return (-1);
	return (chk1 + chk2);
}

// int main(void)
// {
// 	int n = 123;
// 	int c = 'r';

// 	ft_printf("Hello %i %c", n, c);
// }

// %c Prints a single character.
// %s Prints a string (as defined by the common C convention).
// %i Prints an integer in base 10.
// %u Prints an unsigned decimal (base 10) number.
// %d Prints a decimal (base 10) number.
// %i Prints an integer in base 10.
// %p The void * pointer argument has to be printed in hexadecimal format.
// %% Prints a percent sig


