# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalama <asalama@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 12:14:52 by asalama           #+#    #+#              #
#    Updated: 2016/03/23 17:54:23 by asalama          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ls

CC = gcc

CFLAGS = -Wall -Werror -Wextra


SRC = main.c		\

OBJ = $(addprefix $(OBJ_PATH), $(SRC:%.c=%.o))

HEADER_PATH = -I includes/

LIBFT_PATH = libft/libft.a

OBJ_PATH = ./OBJ/

.PHONY: clean fclean re all

all: $(SRC) $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(CC) $(OBJ) $(LIBFT_PATH) -o $(NAME)

$(OBJ_PATH)%.o : %.c
	@echo "\033[1;32m" "Compiling $< into $@" "\033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(HEADER_PATH) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@$(MAKE) clean -C libft

fclean: clean
	@rm -rf $(NAME)

re: fclean all
