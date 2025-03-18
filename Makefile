NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= main.c move_push.c move_swap.c move_rotate.c move_reverse_rotate.c parsing.c sort_mini.c stack_control.c utils.c sort_big.c utils_big.c utils_split.c parse_string.c z_error.c
INC		= push_swap.h
OBJ		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc -g3 $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re