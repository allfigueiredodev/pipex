/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:42:29 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/11 21:52:41 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

fork_manager(t_fctn *fctn)
{
	int i;
	
	i = 1;
	fctn->pid[i][0] = fork();
	stdin_pipe(fctn);
	i++;
	while(i < fctn->total_pipes - 1)
	{	
		middle_pipes(fctn, fctn->pid[i][0], i);
		i++;
	}
	stdout_pipe(fctn, fctn->pid[i][0]);
}