# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 15:52:31 by yayiker           #+#    #+#              #
#    Updated: 2025/04/06 22:13:17 by yayiker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra
MLXFLAGS	=	-L ./minilibx -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libft/libft.a
LIBFTDIR = ./libft
MINILIBX_PATH	=	./minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SRC = src/game_validations.c \
		src/render_img.c \
		src/get_size_map.c \
		src/main.c \
		src/end_game.c \
		src/init_map.c \
		src/game_moves.c \
		src/get_maps.c \
		src/start_validations.c \
		src/path_validation.c

OBJ = $(SRC:%.c=%.o)

all: ${NAME}

${NAME}: $(OBJ)
	$(MAKE) --no-print-directory -C $(MINILIBX_PATH)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(FLAGS) -lm $(SRC) $(MLXFLAGS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	@rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	@rm -rf $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re
