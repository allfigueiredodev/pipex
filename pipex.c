/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:49:58 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/11 21:59:54 by aperis-p         ###   ########.fr       */
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
	fork_manager(&fctn);
	close_all_fds(fctn.fd, fctn.total_pipes + 1);
	// waitpid(pid_1, NULL, 0);
	return(0);
}

//append data to the document >>;
//make sure pipe works with multiple pipes; OK
//emulate the redirect operator <; OK

//int dup2(int oldfd, int newfd);