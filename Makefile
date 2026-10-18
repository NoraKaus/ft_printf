NAME = libftprintf.a

SRC = ft_ntopr.c \
	ft_printf.c \
	ft_puts.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

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