NAME    = push_swap
ARCHIVE = push_swap.a
CC      = cc
CFLAGS  = -Wall -Werror -Wextra
MAKE_LIB = ar -rcs
RM      = rm -f
SRCS = main.c parse_args.c reverse_rotate_command.c \
       split.c stack_utils.c tiny_sort.c error_free.c \
       push_command.c push_swap_command.c push_swap_init.c \
       rotate_command.c stack_init.c swap_command.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(ARCHIVE): $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(ARCHIVE)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
