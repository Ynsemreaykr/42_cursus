# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 11:04:16 by yayiker           #+#    #+#              #
#    Updated: 2025/04/06 22:12:01 by yayiker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rc
RM			= rm -f

SRC =			ft_bzero.c ft_memset.c ft_strchr.c \
				ft_strlen.c ft_strncmp.c ft_strrchr.c \
				ft_substr.c  \
				ft_strtrim.c \
				get_next_line.c get_next_line_utils.c \
				ft_putchar.c ft_putstr.c ft_printf.c ft_putnbr.c

OBJS		= $(SRC:.c=.o)
HDRS		= libft.h

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o: %.c $(HDRS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
