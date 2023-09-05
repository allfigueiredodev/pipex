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

typedef struct s_fnctargs	
{
	char 		*fnct_1;
	char 		**fnctargs_1;
	char 		*fnct_2;
	char 		**fnctargs_2;
	char 		*fnct_path_1;
	char 		*fnct_path_2;
	t_file_paths files_paths;
} t_fnctargs;

void parse_function_flags(char *args_1, char *args_2, t_fnctargs *fnctargs);
void set_fnct_path(char *fnct_1, char *fnct_2, t_fnctargs *fnctargs);
int path_chmod_check(char *argv);
void set_file_paths(char *path_1, char *path_2, t_fnctargs *fnctargs);

#endif