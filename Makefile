# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 19:47:41 by snadji-h          #+#    #+#              #
#    Updated: 2021/11/30 21:49:36 by snadji-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= so_long.c

OBJS		= ${SRCS:.c=.o}

NAME		= so_long

CC			= gcc

RM 			= rm -f

CFLAGS		= -Wall -Wextra
all:		${NAME}

${NAME}:	${OBJS}
			gcc ${OBJS} minilibx/libmlx.a -framework OpenGL -framework AppKit -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
