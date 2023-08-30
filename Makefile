all:
	cc pipex.c -Wall -Werror -Wextra && ./a.out "./file_1.txt" "teste" "teste" "teste"
	# cc *.c && ./a.out