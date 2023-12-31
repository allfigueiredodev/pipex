/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 01:06:44 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/16 05:58:05 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "./libft/libft.h"
# include <errno.h>

typedef struct s_file_paths
{
	char	*path_input_file;
	char	*path_output_file;
}	t_file_paths;

typedef struct s_fctn
{
	int				index;
	char			***fctns;
	char			**fctn_path;
	int				total_pipes;
	t_file_paths	files_paths;
	int				fd[1024][2];
	int				pid[1024][1];
}	t_fctn;

char	**set_fctn_data(char *fct, char **envp);
void	set_file_paths(char *path_1, char *path_2, t_fctn *fctn);
void	argv_filter(t_fctn *fctn, char **argv);
void	close_unused_fds(int (*fds)[2], int pid, int total_fds);
void	close_all_fds(int (*fds)[2], int total_fds);
void	stdin_pipe(t_fctn *fctn);
void	middle_pipes(t_fctn *fctn);
void	stdout_pipe(t_fctn *fctn);
void	set_fds(t_fctn *fctn);
void	fork_manager(t_fctn *fctn);
void	free_args(t_fctn *fctn);
void	free_fctn_data(t_fctn *fctn);
void	free_file_paths(t_fctn *fctn);
void	free_all_data(t_fctn *fctn);
int		chmod_check(int argc, char **argv);
int		chmod_check_file_a(char **argv);
int		chmod_check_file_b(int argc, char **argv);
void	env_path_validator(t_fctn *fctn, char **envp);
void	fctn_path_validator(t_fctn *fctn, char **envp);
char	*right_access(char **all_possible_paths);
void	free_envps_array(char **envps);
void	set_basic_info(t_fctn *fctn, int argc);

#endif