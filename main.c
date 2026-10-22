/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:08:53 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/22 16:49:24 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
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
	// std_ret = printf("STD: %%\n");Precision	
	// printf("FT: %d | STD: %d\n\n", ft_ret, std_ret);

    printf("Flags\n");
	printf("1:%#x\n%#X\n", u, u);
	printf("2:%.0x\n", u);
	printf("3:%#-.10x\n", u);
	printf("4:%#.10x\n", u);
	printf("5:%#0.0x\n", u);
	printf("6:%-010d\n", num);
	printf("7:%10x\n", u);
	printf("8:%010x\n", u);
	printf("9:%010.5x\n", u);
	return (0);
}
