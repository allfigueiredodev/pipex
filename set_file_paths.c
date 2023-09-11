/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_file_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:50:55 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/07 19:14:57 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void set_file_paths(char *path_input, char *path_output, t_fctn *fctn)
{
	fctn->files_paths.path_input_file = (char *)malloc(sizeof(char) * (ft_strlen(path_input) + 1));
	fctn->files_paths.path_output_file = (char *)malloc(sizeof(char) * (ft_strlen(path_output) + 1));
	ft_strlcpy(fctn->files_paths.path_input_file, path_input, (ft_strlen(path_input) + 1));
	ft_strlcpy(fctn->files_paths.path_output_file, path_output, (ft_strlen(path_output) + 1));
}