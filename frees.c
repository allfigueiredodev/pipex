/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:04:18 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/13 19:11:35 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void free_file_paths(t_fctn *fctn)
{
	free(fctn->files_paths.path_input_file);
	free(fctn->files_paths.path_output_file);
}

void free_fctn_data(t_fctn *fctn)
{
	int i;

	i = 0;
	while(fctn->fctn_path[i])
	{
		free(fctn->fctn_path[i]);
		i++;
	}
	free(fctn->fctn_path);
}

void free_args(t_fctn *fctn)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(fctn->fctns[i])
	{
		while(fctn->fctns[i][j])
		{
			free(fctn->fctns[i][j]);
			j++;
		}
		free(fctn->fctns[i][j]);
		free(fctn->fctns[i]);
		i++;
		j = 0;
	}
	free(fctn->fctns);	
}

void free_all_data(t_fctn *fctn)
{
	free_args(fctn);
	free_fctn_data(fctn);
	free_file_paths(fctn);
}