# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 00:42:42 by NekoTintin        #+#    #+#              #
#    Updated: 2024/12/03 00:49:42 by NekoTintin       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = srcs/
INCLUDE_DIR = includes/

OBJ_DIR = objs

SRC = 	ft_printf.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_utils.c \
		ft_print_ptr.c \

SRCS = ${addprefix ${SRC_DIR}, ${SRC}}
OBJECTS = ${addprefix ${OBJ_DIR}/, ${SRCS:.c=.o}}

CC = @cc
CFLAGS = -Wall -Wextra -Werror

# Colours
RED = \033[0;91m
GREEN = \033[0;33m
BLUE = \033[1;34m
YELLOW = \033[1;33m
NC = \033[0m 

all: ${NAME}
	@echo "${GREEN}✅ Build compiled !"

# Compilation de l'exécutable
${NAME}: ${OBJECTS}
	@ar -rcs ${NAME} ${OBJECTS}
	@ranlib ${NAME}

# Règle pour compiler les fichiers objets dans le dossier objs
${OBJ_DIR}/%.o: %.c | ${OBJ_DIR}
	@echo "${BLUE}   🛠️  Compiling $< into $@...${NC}"
	${CC} ${CFLAGS} -c $< -o $@

# Création du répertoire objs si non existant
${OBJ_DIR}:
	@echo "${YELLOW}📂 Creating directory ${OBJ_DIR}...${NC}"
	@mkdir -p ${OBJ_DIR}
	@mkdir -p ${OBJ_DIR}/srcs

# Nettoyage des fichiers objets
clean:
	@echo "${RED}🧹 Cleaning object directory...${NC}"
	@rm -rf ${OBJ_DIR}

# Nettoyage complet
fclean: clean
	@echo "${RED}🧹 Cleaning executable...${NC}"
	@rm -f ${NAME}

# Rebuild complet
re: fclean all

.PHONY: all clean fclean re
