/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:42:29 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/13 15:25:24 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void fork_manager(t_fctn *fctn)
{
	if(fctn->index == 1)
		stdin_pipe(fctn);
	else if(fctn->index > 1 && fctn->index < fctn->total_pipes)
		middle_pipes(fctn);
	else if(fctn->index == fctn->total_pipes)
		stdout_pipe(fctn);
}