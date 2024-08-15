# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 12:05:39 by ggoy              #+#    #+#              #
#    Updated: 2024/08/15 06:01:50 by ggoy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#######################       ARGUMENTS         ################################
################################################################################

NAME		= so_long
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address -g3
MLX_PATH	= ./minilibx-linux
MLX_FLAGS	= -L$(MLX_PATH) -lmlx -lbsd -lXext -lX11 -lm
LIBFT_FLAGS	= -L./libft -lft
CC			= cc
################################################################################
#######################         SOURCES         ################################
################################################################################

SRC_FILES	= main.c\
				utils.c\
				hooks.c\
				make_map.c\
				flood_fill.c\
				free_utils.c\
				map_check.c\
				map_check2.c\
				utils2.c\
				make_map2.c

OBJ_FILES	= $(SRC_FILES:.c=.o)

################################################################################
#######################          RULES          ################################
################################################################################


all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(MLX_FLAGS) $(LIBFT_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

minilibx_linux:
	wget https://cdn.intra.42.fr/document/document/26928/minilibx-linux.tgz

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
