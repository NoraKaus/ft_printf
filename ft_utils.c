/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:25:31 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/23 18:17:44 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	init_struct(t_flags *flags)
{
	flags->type = 0;
	flags->negative = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->width = 0;
	flags->precision = -1;
}

ssize_t	is_flag(char inp)
{
	char	symb[6];
	ssize_t	j;

	j = 0;
	symb[0] = '-';
	symb[1] = '+';
	symb[2] = '0';
	symb[3] = ' ';
	symb[4] = '#';
	symb[5] = '\0';
	while (symb[j])
	{
		if (inp == symb[j])
			return (1);
		j++;
	}
	return (0);
}

ssize_t	is_type(char inp)
{
	char	type[10];
	ssize_t	j;

	j = 0;
	type[0] = 'i';
	type[1] = 'd';
	type[2] = 'c';
	type[3] = 's';
	type[4] = 'x';
	type[5] = 'X';
	type[6] = 'p';
	type[7] = 'u';
	type[8] = '%';
	type[9] = '\0';
	while (type[j])
	{
		if (inp == type[j])
			return (1);
		j++;
	}
	return (0);
}
