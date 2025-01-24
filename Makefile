# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 18:33:43 by sel-abbo          #+#    #+#              #
#    Updated: 2025/01/24 11:56:10 by sel-abbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

all: printf libft
	cc $(FLAGS) server.c -o server libft/libft.a ft_printf/libftprintf.a
	cc $(FLAGS) client.c -o client libft/libft.a ft_printf/libftprintf.a

printf:
	$(MAKE) -C ft_printf
libft:
	$(MAKE) -C libft

bonus: printf libft
	cc $(FLAGS) server_bonus.c -o server_bonus libft/libft.a ft_printf/libftprintf.a
	cc $(FLAGS) client_bonus.c -o client_bonus libft/libft.a ft_printf/libftprintf.a

clean:
	$(MAKE) -C ft_printf clean
	$(MAKE) -C libft clean
	rm -f server client
	rm -f server_bonus client_bonus

fclean:
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C libft fclean
	rm -f server client
	rm -f server_bonus client_bonus

re: fclean all

.PHONY: all printf libft clean fclean re