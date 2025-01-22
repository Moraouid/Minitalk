# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-abbo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 18:33:43 by sel-abbo          #+#    #+#              #
#    Updated: 2025/01/13 16:05:56 by sel-abbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
CC = cc
FLAGS = -Wall -Wextra -Werror
ARCH = ar rcs
RM = rm -f

FILES = client.c server.c

OB = ${FILES:.c=.o}

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OB}
	${ARCH} ${NAME} ${OB}

all: ${NAME}

clean:
	${RM} ${OB}

fclean: clean 
	${RM} ${NAME}

re: fclean all
