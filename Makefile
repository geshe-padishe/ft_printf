NAME			= libftprintf.a

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

FLAGS			= -L ${LIBFT_D} -lft
RM				= rm -f
AR				= ar rcs

SRC_D			= srcs
SRCS_LIST		= ft_printf.c ft_printf_nb.c ft_printf_parse.c
SRC_C			= $(addprefix ${SRC_D}/, ${SRCS_LIST})

INC_D			= includes
HEADER_LIST		= ft_printf.h
HEADER_H		= $(addprefix ${INC_D}/, ${HEADER_LIST})

LIBFT			= libft.a
LIBFT_D			= dyn_libft
LIBFT_A			= $(addprefix ${LIBFT_D}/, ${LIBFT})

OBJS			= ${SRC_C:.c=.o}

all:			${NAME}

${NAME}:		${OBJS}
				make -C ${LIBFT_D}
				cp ${LIBFT_D}/${LIBFT} ${NAME}
				${AR} ${NAME} ${OBJS}

%.o: %.c ${HEADER_H}
				${CC} ${CFLAGS} -I${INC_D} -I${LIBFT_D} -o $@ -c $<

clean:
				$(MAKE) -C ${LIBFT_D} clean
				${RM} ${OBJS}

fclean: clean
				$(MAKE) -C ${LIBFT_D} fclean
				${RM} ${NAME}

re: 			fclean all
