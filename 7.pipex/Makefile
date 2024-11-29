# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 18:40:37 by qupollet          #+#    #+#              #
#    Updated: 2024/11/26 16:24:21 by qupollet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC_DIR = src
OBJ_DIR = objs
LIBFT_DIR = libft
INCLUDE_DIR = include

SRC =	pipex.c \
		find_exec.c \
		utils.c \
		file_management.c \
		execute.c \

SRCS = ${addprefix ${SRC_DIR}/, ${SRC}}
OBJECTS = ${addprefix ${OBJ_DIR}/, ${SRC:.c=.o}}

LIBFT = ${LIBFT_DIR}/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

# Compilation de l'exécutable avec LIBFT
${NAME}: ${OBJECTS} ${LIBFT}
	${CC} ${CFLAGS} ${OBJECTS} ${LIBFT} -o ${NAME}

# Règle pour compiler les fichiers objets dans le dossier objs
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIR}
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -I ${LIBFT_DIR} -c $< -o $@

# Création du répertoire objs si non existant
${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

# Compilation de libft
$(LIBFT): 
	make -C $(LIBFT_DIR)

# Nettoyage des fichiers objets
clean:
	rm -rf ${OBJ_DIR}
	make clean -C ${LIBFT_DIR}

# Nettoyage complet
fclean: clean
	rm -f ${NAME}
	make fclean -C ${LIBFT_DIR}
	rm -rf $ {OBJ_DIR}

# Rebuild complet
re: fclean all

.PHONY: all clean fclean re