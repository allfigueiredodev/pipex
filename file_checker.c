/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:43:25 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/30 17:47:52 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int path_chmod_check(char *argv)
{
	if(access(argv, F_OK) == 0)
	{
		printf("File found\n");
		if(access(argv, R_OK) == 0 && access(argv, W_OK) == 0)
		{
			printf("All rights granted");
			return(1);
		}
		else
		{
			perror("Error");
			return(0);
		}
	}
	else
		perror("Error");
	return (0);	
}