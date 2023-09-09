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
	int pid;
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
	fctn.total_pipes = argc - 3;
	argv_filter(&fctn, argv, argc);
	set_fctn_data(fctn.fctn_1, fctn.fctn_2, &fctn, argc);
	set_file_paths(argv[1], argv[4], &fctn);
	// pid = fork();
	// if(pid == 0)
	// {
	// 	//child process 1
	// 	fd_1[0] = open(fctn.files_paths.path_file_1, O_RDONLY, 0777);
	// 	dup2(fd_1[0], STDIN_FILENO);
	// 	close(fd_1[0]);
	// 	dup2(fd_1[1], STDOUT_FILENO);
	// 	close(fd_1[1]);
	// 	execve(fctn.fctn_path_1, fctn.fctn_1, NULL);
	// }
	// pid = fork();
	// if(pid == 0)
	// {
		
	// }
	// pid = fork();
	// if(pid == 0)
	// {
	// 	//child process 2
	// 	close(fd_1[1]);
	// 	int temp = open(fctn.files_paths.path_file_2, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	// 	dup2(fd_1[0], STDIN_FILENO);
	// 	dup2(temp, STDOUT_FILENO);
	// 	close(fd_1[0]);
	// 	close(temp);
	// 	execve(fctn.fctn_path_2, fctn.fctn_2, NULL);
	// }
	// close(fd_1[0]);
	// close(fd_1[1]);
	// waitpid(pid, NULL, 0);
	// waitpid(pid, NULL, 0);
	// return(0);
}

//append data to the document >>;
//make sure pipe works with multiple pipes; 
//emulate the redirect operator <; OK