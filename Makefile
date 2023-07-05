NAME	=	libftprintf.a

SRC		=	count_print_c.c \
			count_print_s.c \
			count_print_d.c	\
			ft_printf.c 

all: $(NAME)

$(NAME):
	cc -c -Wall -Werror -Wextra $(SRC)
	ar rc $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean