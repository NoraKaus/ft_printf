/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:08:53 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/23 18:17:50 by ekausiny         ###   ########.fr       */
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
	ft_ret = ft_printf("FT : %c, %c\n", 'z', '\0');
	std_ret = printf("STD: %c, %c\n", 'z', '\0');
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);
	printf("Percentages\n");
	ft_ret = ft_printf("FT : %%\n");
	std_ret = printf("STD: %%\n");

printf("=== SIGNED INTEGERS (d, i) ===\n");
	
	printf("--- Plus and Space Flags ---\n");
	ft_ret = ft_printf("FT : %+d, %+d, % d, % d\n", 42, -42, 42, -42);
	std_ret = printf("STD: %+d, %+d, % d, % d\n", 42, -42, 42, -42);
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	printf("--- Zero and Minus Flags (Width) ---\n");
	ft_ret = ft_printf("FT : %05d, %-5d, %05d, %-5d\n", 42, 42, -42, -42);
	std_ret = printf("STD: %05d, %-5d, %05d, %-5d\n", 42, 42, -42, -42);
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	printf("--- Precision and Zero Override ---\n");
	ft_ret = ft_printf("FT : %.5d, %08.5d, %08.5d\n", 42, 42, -42);
	std_ret = printf("STD: %.5d, %08.5d, %08.5d\n", 42, 42, -42);
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	printf("--- Edge Case: Value 0, Precision 0 ---\n");
	ft_ret = ft_printf("FT : [%.0d], [%+.0d], [%5.0d]\n", 0, 0, 0);
	std_ret = printf("STD: [%.0d], [%+.0d], [%5.0d]\n", 0, 0, 0);
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);


	printf("=== UNSIGNED HEXADECIMALS (x, X) ===\n");

	printf("--- Hash Flag Basics ---\n");
	ft_ret = ft_printf("FT : %#x, %#X\n", 42, 42);
	std_ret = printf("STD: %#x, %#X\n", 42, 42);
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	printf("--- Hash with Zero and Width ---\n");
	ft_ret = ft_printf("FT : %#08x, %-#8x\n", 42, 42);
	std_ret = printf("STD: %#08x, %-#8x\n", 42, 42);
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	printf("--- Edge Case: Hash with Value 0 ---\n");
	ft_ret = ft_printf("FT : %#x, %#X\n", 0, 0);
	std_ret = printf("STD: %#x, %#X\n", 0, 0);
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);


	printf("=== STRINGS AND CHARACTERS (s, c) ===\n");

	printf("--- String Width and Justification ---\n");
	ft_ret = ft_printf("FT : %10s, %-10s\n", "hello", "hello");
	std_ret = printf("STD: %10s, %-10s\n", "hello", "hello");
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	printf("--- String Precision (Truncation) ---\n");
	ft_ret = ft_printf("FT : %.3s, %10.3s, %-10.3s\n", "hello", "hello", "hello");
	std_ret = printf("STD: %.3s, %10.3s, %-10.3s\n", "hello", "hello", "hello");
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);
	
	printf("--- Edge Case: NULL String ---\n");
	ft_ret = ft_printf("FT : %s, %10s, %.2s\n", (char *)NULL, (char *)NULL, (char *)NULL);
	std_ret = printf("STD: %s, %10s, %.2s\n", (char *)NULL, (char *)NULL, (char *)NULL);
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);


	printf("=== POINTERS (p) ===\n");

	printf("--- Pointer Width and Justification ---\n");
	int test_var = 42;
	ft_ret = ft_printf("FT : %20p, %-20p\n", &test_var, &test_var);
	std_ret = printf("STD: %20p, %-20p\n", &test_var, &test_var);
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	printf("--- Edge Case: NULL Pointer ---\n");
	ft_ret = ft_printf("FT : %p, %20p\n", NULL, NULL);
	std_ret = printf("STD: %p, %20p\n", NULL, NULL);
	printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	return (0);
}
