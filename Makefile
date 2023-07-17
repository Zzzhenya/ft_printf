CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = 		Printf_utils/print_chr.c \
			Printf_utils/print_str.c \
			Printf_utils/print_int.c \
			Printf_utils/print_ptr.c \
			Printf_utils/print_hex.c \
			Printf_utils/print_uint.c \
			ft_printf.c

OBJS = $(SRCS:.c=.o)

# $@ - target
# $^ - all dependent
# $< - first dependent

all: ${NAME}

${NAME}: $(OBJS)
	$(MAKE) -C ./Libft
	cp Libft/libft.a ${NAME}
	ar rcs ${NAME} ${OBJS}
	
.c.o:
	${CC} ${CFLAGS} -c $^ -o $@

clean:
	$(MAKE) clean -C ./Libft
	rm -f ${OBJS}

fclean: clean
	$(MAKE) fclean -C ./Libft
	rm -f ${NAME}

re: fclean all

tests:
	make fclean
	make
	cc tester.c libftprintf.a
	./a.out
	make fclean
	rm a.out

.PHONY: all fclean re clean tests