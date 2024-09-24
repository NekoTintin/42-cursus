# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 14:26:48 by qupollet          #+#    #+#              #
#    Updated: 2024/09/24 16:53:14 by NekoTintin       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_DIR = srcs/

INCLUDES = includes/

TO_COMPILE = ft_putchar.c \
	ft_putstr.c \
	ft_strcmp.c \
	ft_strlen.c \
	ft_swap.c

SRCS = ${addprefix ${SRCS_DIR}, ${TO_COMPILE}}
OBJECTS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJECTS}
	ar -rcs ${NAME} ${OBJECTS}
	ranlib ${NAME}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
