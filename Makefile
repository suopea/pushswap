NAME = push_swap
SRC = input_validation.c normalization.c push_swap.c sort.c moves.c parsing.c small_sort.c utils.c
LIBFT = libft/libft.a
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cc $(FLAGS) $^ -o $@

$(LIBFT):
	make -C libft
	make -C libft clean

%.o: %.c
	cc $(FLAGS) -c $<

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

rec: re clean

re: fclean all

.PHONY: all re fclean clean rec
.SECONDARY: $(OBJ)
