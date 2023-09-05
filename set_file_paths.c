/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_file_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:50:55 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/04 21:31:33 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void set_file_paths(char *path_1, char *path_2, t_fnctargs *fnctargs)
{
	fnctargs->files_paths.path_file_1 = (char *)malloc(sizeof(char) * (ft_strlen(path_1) + 1));
	fnctargs->files_paths.path_file_2 = (char *)malloc(sizeof(char) * (ft_strlen(path_2) + 1));
	ft_strlcpy(fnctargs->files_paths.path_file_1, path_1, (ft_strlen(path_1) + 1));
	ft_strlcpy(fnctargs->files_paths.path_file_2, path_2, (ft_strlen(path_2) + 1));
}