# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/07 17:31:40 by apyltsov          #+#    #+#              #
#    Updated: 2018/09/08 13:53:40 by apyltsov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= alcu

OBJ_DIR = ./obj/
INC_DIR = ./inc/
SRC_DIR = ./src/

LIBFTDIR := ./libft/

LIBFT = $(LIBFTDIR)/libft.a

SRCFILE = get_next_line.c main.c
 
OBJECTS = $(addprefix $(OBJ_DIR), $(SRCFILE:.c=.o))

CC = gcc
FLAGS = -Wall -Wextra -Werror
HDR_FLAGS = -I $(INC_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(LIBFT) 

$(OBJECTS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	@$(CC) -c $< -o $@ $(FLAGS) $(HDR_FLAGS)

$(LIBFT):
	@make -C $(LIBFTDIR)


clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFTDIR)

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@rm -f $(NAME)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
