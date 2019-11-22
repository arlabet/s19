# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgeymond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 19:12:11 by sgeymond          #+#    #+#              #
#    Updated: 2019/11/20 22:47:55 by nsahloum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = bsq.c 		\
	  calculation.c	\
	  check_map.c	\
	  main.c		\
	  primary_functions.c \
	  read_map.c \
	  specific_functions_bsq.c \
 	  to_gain_lines.c	  

OBJ = ${SRC:.c=.o} 

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ}

${OBJ} : ${SRC}
	${CC} ${CFLAGS} -c ${SRC}

clean : 
	rm ${OBJ}

fclean :
	rm ${OBJ} ${NAME}

re : fclean all
.PHONY : fclean all
