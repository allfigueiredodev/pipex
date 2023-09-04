NAME = pipex
LIBFT_PATH = ./libft
LIBFT_MAKE = $(MAKE) -C $(LIBFT_PATH)
LIBFT_LIB = $(LIBFT_PATH)/libft.a
MAKE = make
CC = cc
FLAGS = -Wall -Werror -Wextra -g3
SRC = pipex.c file_checker.c parse_function_flags.c set_fnct_path.c

OBJS = $(SRC:.c=.o)

all: $(NAME)
	# cc $(SRC) -Wall -Werror -Wextra -g3 && ./pipex ./file_1.txt "ls -la" "grep pipex" ./file_2.txt

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I ./ -Llibft -lft

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I ./

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./pipex

clean:
	rm -rf $(OBJS)
	$(LIBFT_MAKE) clean

fclean: clean
	rm -rf $(NAME)
	$(LIBFT_MAKE) fclean

re: fclean all

.PHONY: all clean fclean re