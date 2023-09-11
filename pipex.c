/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:49:58 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/07 19:30:04 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
	t_fctn fctn;
	int pid_1;
	int pid_2;
	int pid_3;
	int fd[4][2];
	int i = 0;
	
	if(argc < 5)
	{
		printf("Not enough arguments\n");
		return (0);
	}
	if(!path_chmod_check(argv[1]))
		return(0);
	while(i < 4)
	{
		if(pipe(fd[i]) == -1)
		{
			perror("fd");
			return(1);
		};
		i++;
	}
	fctn.total_pipes = argc - 3;
	argv_filter(&fctn, argv);
	set_fctn_data(&fctn);
	set_file_paths(argv[1], argv[argc - 1], &fctn);
	pid_1 = fork();
	if(pid_1 == 0)
	{
		//child process 1
		close_unused_fds(fd, 1, 4);
		fd[0][0] = open(fctn.files_paths.path_input_file, O_RDONLY, 0777);
		dup2(fd[0][0], STDIN_FILENO);
		close(fd[0][0]);
		dup2(fd[1][1], STDOUT_FILENO);
		close(fd[1][1]);
		execve(fctn.fctn_path[0], fctn.fctns[0], NULL);
	}
	pid_2 = fork();
	if(pid_2 == 0)
	{
		//child process 2
		close_unused_fds(fd, 2, 4);
		dup2(fd[1][0], STDIN_FILENO);
		close(fd[1][0]);
		dup2(fd[2][1], STDOUT_FILENO);
		execve(fctn.fctn_path[1], fctn.fctns[1], NULL);
	}
	pid_3 = fork();
	if(pid_3 == 0)
	{
		//child process 3
		close_unused_fds(fd, 3, 4);
		fd[3][1] = open(fctn.files_paths.path_output_file, O_WRONLY | O_TRUNC | O_CREAT, 0777);
		dup2(fd[2][0], STDIN_FILENO);
		close(fd[2][0]);
		dup2(fd[3][1], STDOUT_FILENO);
		close(fd[3][1]);
		execve(fctn.fctn_path[2], fctn.fctns[2], NULL);
	}
	close_all_fds(fd, 4);
	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, NULL, 0);
	waitpid(pid_3, NULL, 0);
	return(0);
}

//append data to the document >>;
//make sure pipe works with multiple pipes; OK
//emulate the redirect operator <; OK

//int dup2(int oldfd, int newfd);