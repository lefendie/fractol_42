# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 11:00:29 by lefendie          #+#    #+#              #
#    Updated: 2021/08/08 13:52:35 by lefendie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

MAIN := $(wildcard main.c)

OBJ_MAIN := $(MAIN:.c=.o)

SRC		:=	$(wildcard error/*.c)\
					$(wildcard image/*.c)\
					$(wildcard fractal/*.c)\
					$(wildcard input/*.c)\
					$(wildcard process/*.c)\
					$(wildcard other/*.c)

OBJ		:= $(SRC:.c=.o)

OBJ_WITH_MAIN:= $(OBJ) ${OBJ_MAIN}

MAIN_BONUS := $(wildcard bonus/main_bonus.c)

OBJ_MAIN_BONUS := $(MAIN_BONUS:.c=.o)

SRC_BONUS 	:=	$(wildcard bonus/image/*.c)\
								$(wildcard bonus/input/*.c)\
								$(wildcard bonus/process/*.c)\
								$(wildcard bonus/fractal/*.c)\
								$(wildcard bonus/other/*.c)

OBJ_BONUS		:= $(SRC_BONUS:.c=.o) ${OBJ} 

OBJ_BONUS_WITH_MAIN		:= $(OBJ_BONUS) ${OBJ_MAIN_BONUS} 

%.o: %.c; ${CC} ${CFLAGS} -o $@ -c $<

RM	= /bin/rm -rf

CC	= clang

CFLAGS	= -Wall -Wextra -Werror -Ilibft -Imlx_linux -Iinclude -g3

LIB = -Llibft -lft -Lmlx_linux -lmlx -lXext -lX11 -lm -lbsd 

%_bonus.o: CFLAGS += -Ibonus/include

${NAME}: ${OBJ_WITH_MAIN}
	${CC} ${OBJ_WITH_MAIN} -o ${NAME} ${LIB}

all: ${NAME} 

bonus: ${OBJ_BONUS_WITH_MAIN}
	${CC} ${OBJ_BONUS_WITH_MAIN} -o ${NAME} ${LIB}

clean:
	${RM} ${OBJ_WITH_MAIN} ${OBJ_BONUS_WITH_MAIN}

fclean:	clean
	${RM} ${NAME}

re:	fclean clean all

.PHONY: re clean fclean all bonus
