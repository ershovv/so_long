# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 16:39:18 by bshawn            #+#    #+#              #
#    Updated: 2021/09/18 16:00:00 by bshawn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEAD = so_long.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LIB = ./libft/libft.a
RM = rm -rf

SRC =	main.c 					\
		./src/valid.c 			\
		./src/game.c 			\
		./src/map.c				\
		./src/control.c			\
		./src/sprites_utils.c 	\
		./src/render.c			\
		./src/animation.c			

OBJ = $(SRC:%.c=%.o)


.o : .c
		$(CC) $(FLAGS) -Imlx $< -o $@

all : minilibx libft $(NAME)

minilibx:
	make -C ./minilibx

libft:
	make -C ./libft

$(NAME) : $(OBJ) $(HEAD)
	$(CC) -g $(CFLAGS) $(OBJ) $(LIB) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
clean:
	$(MAKE) -C ./libft clean
	$(RM) $(OBJ)
	$(RM) $(OBJB)

fclean: clean
	$(RM) ./libft/libft.a
	make clean -C ./minilibx
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean minilibx libft