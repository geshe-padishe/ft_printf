NAME			= libftprintf.a

SRCS_LIST		= \
					ft_printf.c \
					ft_printf_nb.c \
					ft_printf_parse.c \

INC_LIST		= ft_printf.h

SRCS			= $(addprefix ${DIR}/, ${SRCS_LIST})
INC_H			= $(addprefix ${HEADER}/, ${INC})

OBJS			= ${SRCS:.c=.o}

DIR				= srcs
HEADER			= includes

LIBFT_D 		= dyn_libft
LIBFT_A			= libft.a
LIBFT			= $(addprefix ${LIBFT_D/, ${LIBFT_A})
LFLAG 			= -L ${LIBFT_D} -lft


CC				= gcc
FLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}
				make -C $(LIBFT_D)
				cp $(LIBFT_D)/libft.a ./$(NAME)
				ar -rcs ${NAME} ${OBJS}

bonus:			${NAME}

%.o: %.c 
				${CC} ${FLAGS} -I${LIBFT_D} -I${HEADER} -o $@ -c $<

clean:
				@${RM} ${OBJS}
				@make clean -C $(LIBFT_D)

fclean:			clean
				@${RM} ${NAME}
				@make fclean -C $(LIBFT_D)

re:				fclean all
