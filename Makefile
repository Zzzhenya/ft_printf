NAME	=	libftprintf.a

SRC		=	Printf_utils/print_chr.c \
			Printf_utils/print_str.c \
			Printf_utils/print_int.c \
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