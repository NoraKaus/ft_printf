/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 13:08:20 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/22 16:06:42 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void t_parsef(const char *input, ssize_t *i, t_flags *flags)
{
	while (is_flag(input[*i]) && input[*i])
	{
		if (input[*i] == '-')
			flags->minus = 1;
		if (input[*i] == '+')
			flags->plus = 1;
		if (input[*i] == ' ')
			flags->space = 1;
		if (input[*i] == '#')
			flags->hash = 1;
		if (input[*i] == '0')
			flags->zero= 1;
		(*i)++;
	}
	if (ft_isdigit(input[*i]))
		flags->width = ft_parse_n(input, i);
	if (input[*i] == '.')
	{
		flags->precision = 0;
		(*i)++;
	}
	if (ft_isdigit(input[*i]))
		flags->precision = ft_parse_n(input, i);
	if (is_type(input[*i]))
		flags->type = input[*i];
}

ssize_t	ft_parse_n(const char *input, ssize_t *i)
{
	ssize_t	pad;

	pad = 0;
	while (ft_isdigit(input[*i]))
	{
		pad = pad * 10 + (input[*i] - '0');
		(*i)++;
	}
	return (pad);
}

// void print_flags(t_flags *flags)
// {
// 	printf("\ntype %c ", flags->type);
// 	printf("\nminus %d", flags->minus);
// 	printf("\nplus %d ", flags->plus);
// 	printf("\nzero %d ", flags->zero);
// 	printf("\nspace %d ", flags->space);
// 	printf("\nhash %d ", flags->hash);
// 	printf("\nwidth %d ", flags->width);
// 	printf("\nprecision %d ", flags->precision);
// 	printf("\n\nNext");
// }

// int main (void)
// {
// 	char *arr[] = {"%%", "%+ ", "%05p", "%.u", "%.0x", "%.05q",\
// 		"%08.5r"};
// 	t_flags flags;
// 	ssize_t i;

// 	for (int j = 0; j < sizeof(arr)/sizeof(arr[i]); j++)
// 	{
// 		i = 1;
// 		init_struct(&flags);
// 		t_parsef(arr[j],  &i, &flags);
// 		print_flags(&flags);
// 	}

// }

