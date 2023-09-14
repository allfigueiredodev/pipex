/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:43:25 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/14 00:36:14 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int env_path_check(t_fctn *fctn)
{
	int i;

	i = 0;
	while(fctn->fctn_path[i])
	{
		if(access(fctn->fctn_path[i], F_OK) == 0)
			i++;
		else if(access(fctn->fctn_path[i], F_OK) < 0)
		{
			perror("Error");			
			free_all_data(fctn);
			return(0);
		}
	}
	return(1);
}

int chmod_check_file_a(char **argv)
{
	if(access(argv[1], F_OK) == 0)
	{
		if(access(argv[1], R_OK) == 0 && access(argv[1], W_OK) == 0)
			return(1);
	}
	else
	{
		ft_putstr_fd("permission denied: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd("\n", 2);
	}
	return (0);	
}

int chmod_check_file_b(int argc, char **argv)
{
	if(access(argv[argc -1], F_OK) == 0)
	{
		if(access(argv[argc -1], R_OK) == 0 && access(argv[argc -1], W_OK) == 0)
			return(1);
	}
	else
	{
		ft_putstr_fd("permission denied: ", 2);
		ft_putstr_fd(argv[argc -1], 2);
		ft_putstr_fd("\n", 2);
	}
	return (0);	
}

int chmod_check(int argc, char **argv)
{
	if(!chmod_check_file_a(argv) || !chmod_check_file_b(argc, argv))
		return(0);
	else
	{
		printf("Files found\n");
		printf("All rights granted\n");
		return(1);
	}
}