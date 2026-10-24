/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 13:08:20 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/23 18:18:26 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsef(const char *input, ssize_t *i, t_flags *flags)
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
			flags->zero = 1;
		(*i)++;
	}
	if (ft_isdigit(input[*i]))
		flags->width = parse_n(input, i);
	if (input[*i] == '.')
	{
		flags->precision = 0;
		(*i)++;
	}
	if (ft_isdigit(input[*i]))
		flags->precision = parse_n(input, i);
	if (is_type(input[*i]))
		flags->type = input[*i];
}

ssize_t	parse_n(const char *input, ssize_t *i)
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
