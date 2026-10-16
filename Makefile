NAME = libftprintf.a

SRC = ${wildcard ft_*.c}

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c 
	cc ${CFLAGS} -c $< -o $@ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re