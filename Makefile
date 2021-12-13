# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 19:47:41 by snadji-h          #+#    #+#              #
#    Updated: 2021/12/13 17:37:47 by snadji-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= so_long.c mlx_setup.c so_long_map.c so_long_image.c so_long_get_next.c so_long_hook.c ft_itoa.c so_long_everything.c so_long_enemie.c

OBJS		= ${SRCS:.c=.o}

DEPS		= ${SRCS:.c=.d}

NAME		= so_long

CC			= gcc

RM 			= rm -f

CFLAGS		= -Wall -Wextra -Werror -MD
all:		${NAME}

${NAME}:	${OBJS}
			gcc ${OBJS} minilibx/libmlx.a -framework OpenGL -framework AppKit -o ${NAME}

clean:
			${RM} ${OBJS} ${DEPS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

norm:
			norminette ${SRCS} so_long.h

.PHONY:		all clean fclean re

-include ${DEPS}
