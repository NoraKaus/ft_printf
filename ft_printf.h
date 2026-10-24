/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:08:39 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/24 15:56:20 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define BASE_TEN "0123456789"
# define HX_LOW "0123456789abcdef"
# define HX_UP "0123456789ABCDEF"
# define BUFF_SZ 24

typedef struct s_flags
{
	char	type;
	int		negative;
	int		minus;
	int		plus;
	int		zero;
	int		space;
	int		hash;
	int		width;
	int		precision;
}	t_flags;

int		ft_printf(const char *input, ...);
ssize_t	display(const char *input, va_list *list);
ssize_t	handle_output(const char *input, ssize_t *i, va_list *list);
ssize_t	ft_putchar(int c);
ssize_t	ft_putstr(char *str, ssize_t len);
ssize_t	ft_strlen(const char *s);
ssize_t	put_loop(ssize_t len, char s);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
void	init_struct(t_flags *flags);
ssize_t	is_flag(char inp);
ssize_t	is_type(char inp);
void	sanitize_flags(t_flags *flags);
ssize_t	get_width(t_flags *flags);
ssize_t	get_precision(t_flags *flags);
char	*get_prefix(t_flags *flags);
void	parsef(const char *input, ssize_t *i, t_flags *flags);
ssize_t	parse_n(const char *input, ssize_t *i);
ssize_t	ft_chck_nxt(va_list *list, t_flags *flags);
ssize_t	ft_ntopr(unsigned long nb, char *base, char	*num);
ssize_t	output_num(char *num, ssize_t len, t_flags *flags);
ssize_t	left_al(char *prefix, ssize_t zero_pr, ssize_t space_pr,\
	char *num);
ssize_t	right_al(char *prefix, ssize_t zero_pr, ssize_t space_pr,\
	char *num);
ssize_t	handle_string(va_list *list, t_flags *flags);
ssize_t	handle_text(va_list *list, t_flags *flags);
void	null_str(char **str, t_flags *flags);
ssize_t	add_str(char *str, ssize_t len, ssize_t *total);
ssize_t	get_str_len(t_flags *flags, char *str);
ssize_t	zero_right(char *prefix, ssize_t zero_pr, ssize_t space_pr, char *num);
ssize_t	add_pad(ssize_t len, char c, ssize_t *total);
ssize_t	null_ptr(t_flags *flags);

#endif