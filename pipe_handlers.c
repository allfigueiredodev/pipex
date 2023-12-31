/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:59:20 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/16 01:32:04 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	stdin_pipe(t_fctn *fctn)
{
	close_unused_fds(fctn->fd, 1, fctn->total_pipes + 1);
	fctn->fd[0][0] = open(fctn->files_paths.path_input_file, O_RDONLY, 0777);
	dup2(fctn->fd[0][0], STDIN_FILENO);
	close(fctn->fd[0][0]);
	dup2(fctn->fd[1][1], STDOUT_FILENO);
	close(fctn->fd[1][1]);
	execve(fctn->fctn_path[0], fctn->fctns[0], NULL);
	perror("Error");
}

void	middle_pipes(t_fctn *fctn)
{
	close_unused_fds(fctn->fd, fctn->index, fctn->total_pipes + 1);
	dup2(fctn->fd[fctn->index - 1][0], STDIN_FILENO);
	close(fctn->fd[fctn->index - 1][0]);
	dup2(fctn->fd[fctn->index][1], STDOUT_FILENO);
	close(fctn->fd[fctn->index][1]);
	execve(fctn->fctn_path[fctn->index - 1],
		fctn->fctns[fctn->index - 1], NULL);
	perror("Error");
}

void	stdout_pipe(t_fctn *fctn)
{
	close_unused_fds(fctn->fd, fctn->index, fctn->total_pipes + 1);
	fctn->fd[fctn->total_pipes][1] = open(fctn->files_paths.path_output_file,
			O_WRONLY | O_TRUNC | O_CREAT, 0777);
	dup2(fctn->fd[fctn->total_pipes - 1][0], STDIN_FILENO);
	close(fctn->fd[fctn->total_pipes - 1][0]);
	dup2(fctn->fd[fctn->total_pipes][1], STDOUT_FILENO);
	close(fctn->fd[fctn->total_pipes][1]);
	execve(fctn->fctn_path[fctn->total_pipes - 1],
		fctn->fctns[fctn->total_pipes - 1], NULL);
	perror("Error");
}
