NAME = libft.a
AR = ar rcs
RL = ranlib
CC = cc
FLAGS = -Wall -Werror -Wextra
SRC = ft_striteri.c ft_putnbr_fd.c ft_putchar_fd.c ft_strmapi.c \
ft_strlen.c ft_split.c ft_strlcpy.c ft_strtrim.c ft_strdup.c \
ft_strjoin.c ft_substr.c ft_calloc.c ft_atoi.c ft_strlcat.c \
ft_strnstr.c ft_strncmp.c ft_memcmp.c ft_isascii.c ft_strchr.c \
ft_bzero.c ft_isalnum.c ft_isdigit.c ft_isprint.c ft_itoa.c \
ft_memmove.c ft_memchr.c ft_memcpy.c ft_memset.c ft_putendl_fd.c \
ft_putstr_fd.c ft_isalpha.c ft_strrchr.c ft_tolower.c ft_toupper.c \
get_next_line.c get_next_line_utils.c ft_printf_utils.c ft_printf.c \
ft_strcmp.c ft_print_matrix.c

OBJS = $(SRC:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I ./

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RL) $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re