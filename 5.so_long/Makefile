# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 18:40:37 by qupollet          #+#    #+#              #
#    Updated: 2024/09/20 16:23:30 by qupollet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = src
LIBFT_DIR = libft
INCLUDE_DIR = include
MLX_DIR = minilibx

SRC =	map/create_map.c \
		map/map.c \
		map/map2.c \
		game/init.c \
		game/so_long.c \
		game/render_map.c \
		game/render_object.c \
		game/hooks.c \
		game/player_movment.c \
		utils/utils.c \
		utils/utils2.c \
		utils/free_things.c \

SRCS = ${addprefix ${SRC_DIR}/, ${SRC}}
OBJECTS = ${SRCS:.c=.o}

LIBFT = ${LIBFT_DIR}/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I/minilibx -Imlx_linux -g3

all: ${NAME}

${NAME}: ${OBJECTS} LIBFT mlx
	${CC} ${CFLAGS} ${OBJECTS} ${LIBFT} -Lminilibx -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -o ${NAME}

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I ${INCLUDE_DIR} -I ${LIBFT_DIR} -c $< -o $@

LIBFT: 
	make -C $(LIBFT_DIR)

mlx:
	make -C ${MLX_DIR}

clean:
	rm -f ${OBJECTS}
	make clean -C libft

fclean: clean
	rm -f ${NAME}
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
