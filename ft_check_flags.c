/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 13:08:20 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/20 15:30:01 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_add_flags(const char *input, ssize_t *i, va_list *list)
{
	t_flags	*flags;
	ssize_t	count;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (-1);
	count = 0;
	init_struct(flags);
	ft_parsef(input, i, list, flags);
	return (0);
}

void	ft_parsef(const char *input, ssize_t *i, va_list *list, t_flags *flags)
{
	while (!ft_is_alpha(input[*i]) && input[*i])
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
		{
			flags->width = 1;
			flags->width_len = ft_parse_n(input, i, list, flags);
		}
		if (input[*i] == '.')
		{
			flags->precision = ft_parse_n(input, i, list, flags);
		}
		(*i)++;
	}
}

ssize_t	ft_parse_n(const char *input, ssize_t *i, va_list *list, t_flags *flags)
{
	ssize_t	pad;

	pad = 0;
	while (input[*i + 1] >= '0' && input[*i + 1] <= '9')
	{
		pad = pad * 10 + (input[*i + 1] - '0');
		(*i)++;
	}
	return (pad);
}
