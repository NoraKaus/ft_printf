/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:57:58 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/24 17:10:17 by ekausiny         ###   ########.fr       */
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
	while (input[i])
	{
		if (input[i] != '%')
			output = write(1, &input[i], 1);
		else
		{
			if (input[i + 1] == '\0')
				return (total);
			output = handle_output(input, &i, list);
		}
		if (output < 0)
			return (-1);
		total += output;
		i++;
	}
	return (total);
}

ssize_t	handle_output(const char *input, ssize_t *i, va_list *list)
{
	t_flags	flags;
	ssize_t	count;

	count = 0;
	*i += 1;
	init_struct(&flags);
	parsef(input, i, &flags);
	count = ft_chck_nxt(list, &flags);
	if (count < 0)
		return (-1);
	return (count);
}

/*#include <stdio.h>
#include <limits.h> 

int main(void)
{
	int	ft_ret;
	int	std_ret;
	char *null_str = NULL;
	int	num = 42;

	printf("Strings\n");
	ft_ret = ft_printf("FT : %s\n", null_str);
	std_ret = printf("STD: %s\n", null_str);
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	printf("Integers\n");
	ft_ret = ft_printf("FT : %d, %i, %d\n", INT_MIN, INT_MAX, 0);
	std_ret = printf("STD: %d, %i, %d\n", INT_MIN, INT_MAX, 0);
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	printf("Pointers\n");
	ft_ret = ft_printf("FT : %p, %p\n", &num, NULL);
	std_ret = printf("STD: %p, %p\n", &num, NULL);
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	printf("Hexadecimal\n");
	ft_ret = ft_printf("FT : %x, %X, %x\n", 0, UINT_MAX, -42);
	std_ret = printf("STD: %x, %X, %x\n", 0, UINT_MAX, -42);
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	printf("Characters\n");
	ft_ret = ft_printf("FT : %c, %c\n", 'z', '\0');
	std_ret = printf("STD: %c, %c\n", 'z', '\0');
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	printf("Percentages\n");
	ft_ret = ft_printf("FT : %%\n");
	std_ret = printf("STD: %%\n");
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

    printf("Flags\n");
	ft_ret = ft_printf("FT : %%\n");
	std_ret = printf("STD: %%\n");
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	return (0);
}*/