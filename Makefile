NAME			= libftprintf.a

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

FLAGS			= -L ${LIBFT_D} -lft
RM				= rm -f

SRC_D			= srcs
SRCS_LIST		= ft_printf.c ft_printf_nb.c ft_printf_parse.c
SRC_C			= $(addprefix ${SRC_D}/, ${SRCS_LIST})

INC_D			= includes
HEADER			= ft_printf.h

OBJS			= ${SRC_C:.c=.o}

LIBFT_D			= dyn_libft

all:			${NAME}

${NAME}:		${OBJS}
				$(MAKE) -C ${LIBFT_D}
				${CC} ${CFLAGS} ${OBJS} ${FLAGS} -o ${NAME}

%.o: %.c
				${CC} ${CFLAGS} -I${INC_D} -c $< -o ${<:.c=.o}

clean:
				$(MAKE) -C ${LIBFT_D} clean
				${RM} ${OBJS}

fclean: clean
				$(MAKE) -C ${LIBFT_D} fclean
				${RM} ${NAME}

re: 			fclean all
