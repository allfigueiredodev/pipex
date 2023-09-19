NAME = pipex
LIBFT_PATH = ./libft
LIBFT_MAKE = $(MAKE) -C $(LIBFT_PATH)
LIBFT_LIB = $(LIBFT_PATH)/libft.a
MAKE = make
CC = cc
FLAGS = -Wall -Werror -Wextra -g3
SRC = pipex.c pipe_handlers.c fork_manager.c \
set_fds.c close_fds.c argv_filter.c file_checker.c\
set_fctn_data.c set_file_paths.c frees.c set_basic_info.c

OBJS = $(SRC:.c=.o)

all: $(NAME)
	
$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I ./ -Llibft -lft

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I ./

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes -s ./pipex ./file_1.txt "sort" "tr a-z A-Z" "grep PIPEX" ./file_2.txt

bonus: all

clean:
	rm -rf $(OBJS)
	$(LIBFT_MAKE) clean

fclean: clean
	rm -rf $(NAME)
	$(LIBFT_MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
