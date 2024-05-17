# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qupollet <quentinpollet27@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 14:26:48 by qupollet          #+#    #+#              #
#    Updated: 2024/05/17 14:07:01 by qupollet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRCS_DIR = srcs/

INCLUDES = includes/

TO_COMPILE = ft_display_file.c \

SRCS = ${addprefix ${SRCS_DIR}, ${TO_COMPILE}}
OBJECTS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJECTS}
	${CC} ${OBJECTS} -o ${NAME}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

.PHONY: all clean fclean
