/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:08:53 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/20 12:53:09 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h> 

int main(void)
{
	// int	ft_ret;
	// int	std_ret;
	// char *null_str = NULL;
	int	num = 42;
	int	d = 5;
	int	n = -42;
	unsigned int u = 123;
	char str[] = "super";
	

	// printf("Strings\n");
	// ft_ret = ft_printf("FT : %s\n", null_str);
	// std_ret = printf("STD: %s\n", null_str);
	// printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	// printf("Integers\n");
	// ft_ret = ft_printf("FT : %d, %i, %d\n", INT_MIN, INT_MAX, 0);
	// std_ret = printf("STD: %d, %i, %d\n", INT_MIN, INT_MAX, 0);
	// printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	// printf("Pointers\n");
	// ft_ret = ft_printf("FT : %p, %p\n", &num, NULL);
	// std_ret = printf("STD: %p, %p\n", &num, NULL);
	// printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	// printf("Hexadecimal\n");
	// ft_ret = ft_printf("FT : %x, %X, %x\n", 0, UINT_MAX, -42);
	// std_ret = printf("STD: %x, %X, %x\n", 0, UINT_MAX, -42);
	// printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	// printf("Characters\n");
	// // Note: Testing null character '\0' is tricky because it doesn't print visibly
	// ft_ret = ft_printf("FT : %c, %c\n", 'z', '\0');
	// std_ret = printf("STD: %c, %c\n", 'z', '\0');
	// printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

	// printf("Percentages\n");
	// ft_ret = ft_printf("FT : %%\n");
	// std_ret = printf("STD: %%\n");
	// printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

    printf("Flags\n");
	printf("prec: %#p \n %p\n", str, str);
	printf("hash %p\n", n);
	printf("hash %.0p\n", num);
	printf("space %-.10d\n", num);
	printf("space %.10d\n", num);
	printf("space % d\n", n);
	printf("zero %-.5i\n", n);
	printf("zero %+010d\n", num);
	printf(" %05u\n", u);
	printf("plus %0.5i\n", n);
	printf(" %.10u\n", u);
	printf(" %010.5d\n", n);
	return (0);
}
