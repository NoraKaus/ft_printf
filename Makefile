NAME = libftprintf.a

SRC = ft_check_flags.c\
	ft_check_next.c\
	ft_num_conv.c\
	ft_printf.c\
	ft_process.c\
	ft_utils.c\
	ft_utils_puts.c\
	ft_utils_padding.c\
	ft_handle_txt.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

bonus: all

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c 
	cc ${CFLAGS} -I. -c $< -o $@ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re