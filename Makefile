# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalama <asalama@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 12:14:52 by asalama           #+#    #+#              #
#    Updated: 2016/06/03 18:35:16 by asalama          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

SRC_PATH = ./SRC/

SRC_NAME = main.c				\
		   error.c				\
		   argv_list.c			\
		   print.c				\
		   sort.c				\
		   list_tools.c			\
		   position.c			\
		   sort_file_dir.c		\
		   error_list.c			\

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH = ./OBJ/

OBJ = $(addprefix $(OBJ_PATH), $(SRC_NAME:%.c=%.o))

HEADER_PATH = -I includes/

LIBFT_PATH = libft/libft.a

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJ) $(SRC)
	@$(MAKE) -C libft
	@$(CC) $(OBJ) $(LIBFT_PATH) -o $(NAME)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@echo "\033[1;32m" "Compiling $< into $@" "\033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(HEADER_PATH) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@$(MAKE) clean -C libft

fclean: clean
	@rm -rf $(NAME)

re: fclean all
