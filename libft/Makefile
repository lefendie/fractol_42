# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 11:00:29 by lefendie          #+#    #+#              #
#    Updated: 2021/08/01 16:59:16 by lefendie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		:=	$(wildcard is_func/*.c)\
					$(wildcard error/*.c)\
					$(wildcard converter/*.c)\
					$(wildcard string/*.c)\
					$(wildcard memory/*.c)\
					$(wildcard list/*.c)\
					$(wildcard print/*.c)\
					$(wildcard other/*.c)

OBJ	= ${SRC:.c=.o}

RM	= /bin/rm -rf

CC	= /usr/bin/clang

LIB = /usr/bin/ar -rcs

CFLAGS	= -Werror -Wextra -Wall -I .

%.o: %.c; ${CC} ${CFLAGS} -o $@ -c $<

${NAME}: ${OBJ}
	${LIB} ${NAME} ${OBJ}

all: ${NAME} 

clean:
	${RM} ${OBJ} ${OBJB}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: re clean fclean all so exec
