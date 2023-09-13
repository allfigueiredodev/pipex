/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:42:29 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/12 21:53:58 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void fork_manager(t_fctn *fctn)
{
	if(fctn->index == 1)
	{
		// fprintf(stderr, "stdin\n");
		stdin_pipe(fctn);
	}
	else if(fctn->index > 1 && fctn->index < fctn->total_pipes)
	{
		// fprintf(stderr, "middle_pipes\n");	
		middle_pipes(fctn, fctn->index);
	}
	else if(fctn->index == fctn->total_pipes)
	{
		// fprintf(stderr, "stdout\n");
		stdout_pipe(fctn);
	}
}