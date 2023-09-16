/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:49:58 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/16 01:24:55 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_fctn	fctn;

	if (argc < 5)
	{
		printf("Not enough arguments\n");
		return (0);
	}
	if (!chmod_check(argc, argv))
		exit(0);
	fctn.total_pipes = argc - 3;
	fctn.index = 1;
	set_fds(&fctn);
	argv_filter(&fctn, argv);
	env_path_validator(&fctn, envp);
	set_file_paths(argv[1], argv[argc - 1], &fctn);
	while (fctn.index <= fctn.total_pipes)
	{
		fctn.pid[fctn.index][0] = fork();
		if (fctn.pid[fctn.index][0] == 0)
			fork_manager(&fctn);
		fctn.index++;
	}
	close_all_fds(fctn.fd, fctn.total_pipes + 1);
	wait(NULL);
	free_all_data(&fctn);
	return (0);
}
