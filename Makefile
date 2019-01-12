# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apytlsov <apytlsov@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/07 17:31:40 by apyltsov          #+#    #+#              #
#    Updated: 2019/01/12 18:03:55 by apytlsov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= alcu

OBJ_DIR = ./obj/
INC_DIR = ./inc/
SRC_DIR = ./src/

LIBFTDIR := ./libft/

LIBFT = $(LIBFTDIR)/libft.a

SRCFILE = get_next_line.c main.c game.c bot.c
 
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
