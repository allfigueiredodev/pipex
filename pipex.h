#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "./libft/libft.h"
#include <errno.h>

typedef struct s_file_paths
{
	char *path_file_1;
	char *path_file_2;
} t_file_paths;

typedef struct s_fctn	
{
	// char 		**fctn;
	char 		**fctns;
	char 		**fctn_path;
	// int			total_pipes;
	t_file_paths files_paths;
} t_fctn;

void 	parse_function_flags(t_fctn *fctn, int argc);
void 	set_fctn_data(char *fctn_1, char *fctn_2, t_fctn *fctn, int argc);
int 	path_chmod_check(char *argv);
void 	set_file_paths(char *path_1, char *path_2, t_fctn *fctn);
void	argv_filter(t_fctn *fctn, char **argv, int argc)

#endif