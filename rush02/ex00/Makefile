# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/07/20 11:01:42 by coscialp     #+#   ##    ##    #+#        #
#    Updated: 2019/07/20 19:23:36 by coscialp    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRCS		= ./srcs/main.c ./srcs/ft_display.c ./srcs/ft_atoi.c ./srcs/check_str.c ./srcs/ft_split.c

OBJS		= ${SRCS:.c=.o}

FLAG		= -Wall -Werror -Wextra

HEADER		= ./includes/

NAME		= Rush-02

.c.o:
			cc -c ${FLAG} $< -o ${<:.c=.o} -I ${HEADER}

all:		${NAME}

${NAME}:	${OBJS}
			cc ${FLAG} -o ${NAME} ${OBJS}
clean:
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean ${NAME}

.PHONY:		clean fclean re
