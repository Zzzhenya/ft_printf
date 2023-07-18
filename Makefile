NAME = libftprintf.a

SRCS = 		Printf_utils/print_chr.c \
			Printf_utils/print_str.c \
			Printf_utils/print_int.c \
			Printf_utils/print_ptr.c \
			Printf_utils/print_hex.c \
			Printf_utils/print_uint.c \
			ft_printf.c

OBJS = 		print_chr.o \
			print_str.o \
			print_int.o \
			print_ptr.o \
			print_hex.o \
			print_uint.o \
			ft_printf.o

all: $(NAME)

$(NAME): Libft/libft.a
	cc -c -Wall -Werror -Wextra $(SRCS)
	ar rcs $(NAME) $(OBJS)

Libft/libft.a:
	$(MAKE) -C ./Libft
	cp Libft/libft.a $(NAME)

clean:
	$(MAKE) clean -C ./Libft
	rm -f $(OBJS)

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

.PHONY: all fclean re clean tests