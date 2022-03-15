SRCS	= free.c ft_split_cmds.c get_cmd.c \
		main.c pipex_utils.c get_next_line_utils.c \
		pipex.c ft_split.c get_status.c \

SRCBS	= free_bonus.c ft_split_cmds_bonus.c get_cmd_bonus.c \
		main_bonus.c pipex_utils_bonus.c \
		pipex_bonus.c ft_split_bonus.c get_status_bonus.c get_next_line_bonus.c \
		get_next_line_utils_bonus.c \

OBJBS	= ${SRCBS:.c=.o}

OBJS	= ${SRCS:.c=.o}

NAME	= pipex

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

bonus:	${OBJB}
			@make OBJS="${OBJBS}"

all:		${NAME}

clean:
				${RM} ${OBJBS} ${OBJS}

fclean: 	clean
				${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re