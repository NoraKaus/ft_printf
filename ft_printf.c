/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:57:58 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/20 15:25:38 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_add_flags(const char *input, ssize_t *i, va_list *list);
void	init_struct(t_flags *flags);
void	ft_parsef(const char *input, ssize_t *i, va_list *list, t_flags *flags);

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
			if (is_flag(input, i))
			{
				if (ft_add_flags(input, i, list) != 1)
					return (-1);
			}
			output = ft_chck_nxt(input, i + 1, list, flags);
			i++;
		}
		if (output < 0)
			return (-1);
		total += output;
	}
	return (total);
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
