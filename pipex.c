/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:49:58 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/12 22:01:27 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
	t_fctn fctn;
	
	if(argc < 5)
	{
		printf("Not enough arguments\n");
		return (0);
	}
	if(!path_chmod_check(argv[1]))
		return(0);
	fctn.total_pipes = argc - 3;
	fctn.index = 1;
	set_fds(&fctn);
	argv_filter(&fctn, argv);
	set_fctn_data(&fctn);
	set_file_paths(argv[1], argv[argc - 1], &fctn);
	while(fctn.index <= fctn.total_pipes)
	{
		fctn.pid[fctn.index][0] = fork();
		if(fctn.pid[fctn.index][0] == 0)
		{
			printf("actual index: %d\n", fctn.index);
			fork_manager(&fctn);
		}
		printf("pid: %d\n", fctn.pid[fctn.index][0]);
		waitpid(fctn.pid[fctn.index][0], NULL, 0);
		fctn.index++;
	}
	close_all_fds(fctn.fd, fctn.total_pipes + 1);
	return(0);
}

//int dup2(int oldfd, int newfd);