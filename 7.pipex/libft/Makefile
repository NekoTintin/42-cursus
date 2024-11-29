# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 10:29:40 by qupollet          #+#    #+#              #
#    Updated: 2024/11/12 14:05:20 by qupollet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDES = libft

TO_COMPILE =	ft_atoi.c \
				ft_itoa.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_memchr.c \
				ft_memcpy.c \
				ft_memset.c \
				ft_memmove.c \
				ft_memcmp.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putstr_fd.c \
				ft_putnbr_fd.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlen.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_split.c \
				ft_strtrim.c \
				ft_strncmp.c \
				ft_strrchr.c \
				ft_strnstr.c \
				ft_strmapi.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				get_next_line.c \
				ft_utils.c \
				ft_printf.c \
				ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \
				ft_lstlast_bonus.c

SRCS = ${TO_COMPILE}
OBJECTS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@

${NAME}: ${OBJECTS}
	ar -rcs ${NAME} ${OBJECTS}
	ranlib ${NAME}

so:
	${CC} -nostartfiles -fPIC ${CFLAGS} ${SRCS}
	gcc -nostartfiles -shared -o libft.so ${OBJECTS}
	
clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
