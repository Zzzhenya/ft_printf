NAME	=	libftprintf.a

SRC		=	Printf_utils/print_chr.c \
			Printf_utils/print_str.c \
			Printf_utils/print_int.c \
			Printf_utils/print_ptr.c \
			Printf_utils/print_hex.c \
			Printf_utils/print_uint.c \
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

tests:
	make fclean
	make
	cc tester.c libftprintf.a
	./a.out | cat -e
	make fclean
	rm a.out

.PHONY: all fclean re clean tests