NAME	= libft

SRC		= ft_strlen.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		 
INC		= libft.h
OBJ		= $(SRC:.c=.o)

BONUS	= 
B_OBJ	= $(BONUS:.c=.o)


CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror

:%.c%.o $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME).a $(OBJ)

clean:
	$(RM) $(OBJ) $(B_OBJ)

fclean:	clean
	$(RM) $(NAME).a

re: fclean all

bonus:			$(OBJ)	$(B_OBJ)
					ar -rcs $(NAME).a $(OBJ) $(B_OBJ)


.PHONY:			all, clean, fclean, re