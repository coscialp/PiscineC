# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/07/18 00:50:06 by coscialp     #+#   ##    ##    #+#        #
#    Updated: 2019/07/19 11:14:23 by coscialp    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRCS		= ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c

OBJS		= ${SRCS:.c=.o}

HEADER		= ./includes/

FLAG		= -c -Wall -Wextra -Werror

NAME		= libft.a

.c.o:
			gcc ${FLAG} $< -o ${<:.c=.o} -I ${HEADER}

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			rm -f ${OBJS}

fclean:	clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
