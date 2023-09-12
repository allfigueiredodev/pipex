/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:49:58 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/12 17:20:21 by aperis-p         ###   ########.fr       */
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
	set_fds(&fctn);
	argv_filter(&fctn, argv);
	set_fctn_data(&fctn);
	set_file_paths(argv[1], argv[argc - 1], &fctn);
	fctn.pid[1][0] = fork();
	if(fctn.pid[1][0] == 0)
		fork_manager(&fctn);
	// fork_manager(&fctn);
	wait(NULL);
	close_all_fds(fctn.fd, fctn.total_pipes + 1);
	// waitpid(fctn.pid[1][0], NULL, 0);
	return(0);
}

//int dup2(int oldfd, int newfd);