# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 16:15:56 by qupollet          #+#    #+#              #
#    Updated: 2024/12/02 16:31:41 by qupollet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = src
OBJ_DIR = objs
INCLUDE_DIR = include
MLX_DIR = minilibx
LIBFT_DIR = libft

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
OBJECTS = ${addprefix ${OBJ_DIR}/, ${SRC:.c=.o}}

LIBFT = ${LIBFT_DIR}/libft.a

CC = @cc
CFLAGS = -Wall -Wextra -Werror -g3 -I/minilibx -Imlx_linux

# Colours
RED = \033[0;91m
GREEN = \033[0;33m
BLUE = \033[1;34m
YELLOW1 = \033[1;33m
NC = \033[0m 

all: ${NAME}
	@echo "${GREEN}✅ Build compiled !"

${LIBFT}:
	@echo "${BLUE}🛠️  Compiling LIBFT ${NC}"
	@make -C ${LIBFT_DIR}

${MLX}:
	@echo "${BLUE}🛠️  Compiling Minilibx ${NC}"
	@make -C ${MLX_DIR}

# Compilation de l'exécutable
${NAME}: ${LIBFT} ${MLX} ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} ${LIBFT} -Lminilibx -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -o ${NAME}

# Règle pour compiler les fichiers objets dans le dossier objs
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIR}
	@echo "${BLUE}🛠️  Compiling $< into $@...${NC}"
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -I ${LIBFT_DIR} -c $< -o $@

# Création du répertoire objs si non existant
${OBJ_DIR}:
	@echo "${YELLOW}📂 Creating directories ${OBJ_DIR}...\n${NC}"
	@mkdir -p ${OBJ_DIR}
	@mkdir -p ${OBJ_DIR}/game
	@mkdir -p ${OBJ_DIR}/utils
	@mkdir -p ${OBJ_DIR}/map

# Nettoyage des fichiers objets
clean:
	@echo "${RED}🧹 Cleaning object directory...${NC}"
	@make clean -C libft
	@rm -rf ${OBJ_DIR}

# Nettoyage complet
fclean: clean
	@echo "${RED}🧹 Cleaning executable...${NC}"
	@make fclean -C libft
	@rm -f ${NAME}
	@rm -rf $ {OBJ_DIR}

# Rebuild complet
re: fclean all

.PHONY: all clean fclean re
