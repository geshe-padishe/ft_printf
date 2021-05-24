NAME			= libftprintf.a

SRCS_LIST		= \
					ft_printf.c \
					ft_printf_nb.c \
					ft_printf_parse.c \

SRCS			= $(addprefix ${DIR}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

DIR				= srcs
HEADER			= includes

LIBFT 			= dyn_libft

CC				= gcc
FLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}
				@make -C $(LIBFT)
				@cp $(LIBFT)/libft.a ./$(NAME)
				@ar -rcs ${NAME} ${OBJS}

bonus:			${NAME}

%.o: %.c
				@${CC} ${FLAGS} -Idyn_libft -I ${HEADER} -o $@ -c $<

clean:
				@${RM} ${OBJS}
				@make clean -C $(LIBFT)

fclean:			clean
				@${RM} ${NAME}
				@make fclean -C $(LIBFT)

re:				fclean all
