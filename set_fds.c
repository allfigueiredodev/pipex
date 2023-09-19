/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:09:45 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/16 01:34:34 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_fds(t_fctn *fctn)
{
	int	i;

	i = 0;
	while (i < fctn->total_pipes + 1)
	{
		if (pipe(fctn->fd[i]) == -1)
		{
			perror("fd");
			return ;
		}
		i++;
	}
}
