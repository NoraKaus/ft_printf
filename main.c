/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:08:53 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/18 19:08:54 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
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
	// Note: Testing null character '\0' is tricky because it doesn't print visibly
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
}
