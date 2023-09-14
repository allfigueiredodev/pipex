/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:09:45 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/13 17:16:53 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void set_fds(t_fctn *fctn)
{
	int i;

	i = 0;
	while(i < fctn->total_pipes + 1)
	{
		if(pipe(fctn->fd[i]) == -1)
		{
			perror("fd");
			return ;
		};
		i++;
	}
}

// int main(void)
// {
// 	t_fctn fctn;
// 	int i = 0;
	
// 	fctn.total_pipes = 20;
// 	set_fds(&fctn);
// 	while(i < fctn.total_pipes)
// 	{
// 		printf("in: %d\n", fctn.fd[i][0]);
// 		printf("out: %d\n", fctn.fd[i][1]);
// 		i++;
// 	}
// }