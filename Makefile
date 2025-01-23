# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 18:33:43 by sel-abbo          #+#    #+#              #
#    Updated: 2025/01/23 11:53:17 by sel-abbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

all: printf libft
	cc $(FLAGS) server.c -o server libft/libft.a ft_printf/libftprintf.a utils.c
	cc $(FLAGS) client.c -o client libft/libft.a ft_printf/libftprintf.a

printf:
	$(MAKE) -C ft_printf
libft:
	$(MAKE) -C libft

clean:
	$(MAKE) -C ft_printf clean
	$(MAKE) -C libft clean
	rm -f server client 

fclean:
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C libft fclean
	rm -f server client

re: fclean all

.PHONY: all printf libft clean fclean re