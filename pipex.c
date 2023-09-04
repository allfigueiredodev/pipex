/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:49:58 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/01 21:52:43 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
	t_fnctargs fnctargs;
	int pid_1;
	// int pid_2;
	int fd_1[2];
	
	if(argc < 5)
	{
		printf("Not enough arguments\n");
		return (0);
	}
	if(!path_chmod_check(argv[1]))
		return(0);
	if(pipe(fd_1) == -1)
	{
		perror("fd_1");
		return(1);
	}
	parse_function_flags(argv[2], argv[3], &fnctargs);
	set_fnct_path(fnctargs.fnct_1, fnctargs.fnct_2, &fnctargs);
	pid_1 = fork();
	if(pid_1 == 0)
	{
		//child process 1
		close(fd_1[0]);
		dup2(fd_1[1], STDOUT_FILENO);
		close(fd_1[1]);
		execve(fnctargs.fnct_path_1, fnctargs.fnctargs_1, NULL);
	}
	waitpid(pid_1, NULL, 0);
	close(fd_1[1]);
	dup2(fd_1[0], STDIN_FILENO);
	close(fd_1[0]);
	execve(fnctargs.fnct_path_2, fnctargs.fnctargs_2, NULL);

	// pid_2 = fork();
	// if(pid_2 == 0)
	// {
	// 	//child process 2
	// 	close(fd_1[1]);
	// 	dup2(fd_1[0], STDIN_FILENO);
	// 	close(fd_1[0]);
	// 	execve(fnctargs.fnct_path_2, fnctargs.fnctargs_2, NULL);
	// }
	// close(fd_1[0]);
	// close(fd_1[1]);
	// waitpid(pid_2, NULL, 0);
	return(0);
}