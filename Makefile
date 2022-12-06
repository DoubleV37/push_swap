# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviovi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 16:15:09 by vviovi            #+#    #+#              #
#    Updated: 2022/12/06 11:43:37 by vviovi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -O3 -ggdb3

CC = clang

NAME = push_swap

INCLUDES = -I . -I libft

LIBFTFLAGS = -L libft -lft

SRC = 	main.c \
		parsing.c \
		verif_parsing.c \
		utils.c

OBJ = ${SRC:.c=.o}

%.o : %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@echo "╔═════════════════════╗"
	@echo "║ Compiling push_swap ║"
	@echo "╚═════════════════════╝"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFTFLAGS) -o $(NAME)

clean :
	@$(MAKE) -C libft clean
	@echo "╔════════════════════╗"
	@echo "║ Cleaning push_swap ║"
	@echo "╚════════════════════╝"
	@rm -f $(OBJ)

fclean : clean
	@$(MAKE) -C libft fclean
	rm -f $(NAME)

re : fclean all

all : $(NAME)

norm : re
	@echo "norminette : nb OK / nb total"
	@norminette | grep "OK" | wc -l
	@echo -n "/"
	@norminette | wc -l

.PHONY: clean fclean re all norm
