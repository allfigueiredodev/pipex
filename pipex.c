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
	int pid;
	
	if(argc < 5)
	{
		printf("Not enough arguments\n");
		return (0);
	}
	if(!path_chmod_check(argv[1]))
		return(0);
	parse_function_flags(argv[2], argv[3], &fnctargs);	
	set_fnct_path(fnctargs.fnct_1, fnctargs.fnct_2, &fnctargs);
	pid = fork();
	if (pid != 0)
	{
		//parent process
		// wait(NULL);
		execve(fnctargs.fnct_path_1, fnctargs.fnctargs_1, NULL);
	}
	else
		//child process
		execve(fnctargs.fnct_path_2, fnctargs.fnctargs_2, NULL);
	return(0);
}