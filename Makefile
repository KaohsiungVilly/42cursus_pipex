SRCS	= free.c ft_split_cmds.c get_cmd.c main.c pipex_utils.c \
		pipex.c ft_split.c get_status.c get_next_line.c get_next_line_utils.c \

OBJS	= ${SRCS:.c=.o}

NAME	= pipex

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				${CC} ${CFLAGS} ${LIBFT} ${OBJS} -o ${NAME}

bonus:	${OBJS}
				${CC} ${CFLAGS} ${LIBFT} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
				${RM} ${OBJS}

fclean: 	clean
				${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re