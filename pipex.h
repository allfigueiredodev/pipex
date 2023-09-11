#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "./libft/libft.h"
#include <errno.h>

# define BIN_PATH "/usr/bin/"

typedef struct s_file_paths
{
	char *path_input_file;
	char *path_output_file;
} t_file_paths;

typedef struct s_fctn	
{
	// char 		**fctn;
	char 		***fctns;
	char 		**fctn_path;
	int			total_pipes;
	t_file_paths files_paths;
} t_fctn;

void 	set_fctn_data(t_fctn *fctn);
int 	path_chmod_check(char *argv);
void 	set_file_paths(char *path_1, char *path_2, t_fctn *fctn);
void	argv_filter(t_fctn *fctn, char **argv);
void 	close_unused_fds(int (* fds)[2], int pid, int total_fds);
void close_all_fds(int (* fds)[2], int total_fds);

#endif