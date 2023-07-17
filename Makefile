NAME = libftprintf.a

SRCS = 		Printf_utils/print_chr.c \
			Printf_utils/print_str.c \
			Printf_utils/print_int.c \
			Printf_utils/print_ptr.c \
			Printf_utils/print_hex.c \
			Printf_utils/print_uint.c \
			ft_printf.c

all: $(NAME)

$(NAME): libft
	cc -c -Wall -Werror -Wextra $(SRCS)
	ar rcs $(NAME) *.o

libft:
	$(MAKE) -C ./Libft
	cp Libft/libft.a $(NAME)

clean:
	$(MAKE) clean -C ./Libft
	rm -f *.o

fclean: clean
	$(MAKE) fclean -C ./Libft
	rm -f $(NAME)

re: fclean all

tests:
	make re
	cc tester.c libftprintf.a
	./a.out
	make fclean
	rm a.out

.PHONY: all fclean re clean tests libft