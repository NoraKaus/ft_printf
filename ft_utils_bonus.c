/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:25:31 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/20 14:33:47 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

void	init_struct(t_flags *flags)
{
	flags->negative = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->width = 0;
	flags->width_len = 0;
	flags->precision = -1;
}

ssize_t	is_flag(const char *input, ssize_t *i)
{
	char	symb[7];
	ssize_t	j;

	j = 0;
	symb[0] = '-';
	symb[1] = '+';
	symb[2] = '0';
	symb[3] = ' ';
	symb[4] = '.';
	symb[5] = '#';
	symb[6] = '\0';
	while (symb[j])
	{
		if (input[*i] == symb[j])
			return (1);
		j++;
	}
	return (0);
}

