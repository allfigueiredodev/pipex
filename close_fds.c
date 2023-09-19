/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 01:35:58 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/16 01:37:20 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_unused_fds(int (*fds)[2], int pid, int total_fds)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < total_fds)
	{
		if (fds[i][j] != fds[pid - 1][j])
			close(fds[i][j]);
		i++;
	}
	i = 0;
	j = 1;
	while (i < total_fds)
	{
		if (fds[i][j] != fds[pid][j])
			close(fds[i][j]);
		i++;
	}
}

void	close_all_fds(int (*fds)[2], int total_fds)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < total_fds)
	{
		close(fds[i][j]);
		close(fds[i][j + 1]);
		i++;
	}
}
