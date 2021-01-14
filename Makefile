NAME = libftprintf.a
SRCS = \
	ft_printf.c \
	ft_print_int.c \
	ft_print_string.c \
	ft_output.c \
	ft_putchar_fd.c \
	ft_putnbr.c \
	ft_strchr.c
#SRCS_B = \

OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}
HEADERS = .
RM = rm -f
CC = gcc
CFLAG = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAG} -I ${HEADERS} -c $< -o ${<:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus: ${OBJS} ${OBJS_B}
	ar rc ${NAME} ${OBJS_B} ${OBJS_B}

clean:
	${RM} ${OBJS} ${OBJS_B}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all fclean clean re bonus