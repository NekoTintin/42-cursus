# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 10:29:40 by qupollet          #+#    #+#              #
#    Updated: 2024/06/24 15:59:03 by qupollet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = srcs/
INCLUDE_DIR = includes/

SRC = ft_printf.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_utils.c \
		ft_print_ptr.c \

SRCS = ${addprefix ${SRC_DIR}, ${SRC}}
OBJECTS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ${INCLUDE_DIR}

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:  ${OBJECTS}
	ar -rcs ${NAME} ${OBJECTS}
	ranlib ${NAME}
	
clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
