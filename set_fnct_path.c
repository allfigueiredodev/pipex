/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fnct_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:43:49 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/04 20:47:30 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void set_fnct_path(char *fnct_1, char *fnct_2, t_fnctargs *fnctargs)
{
	char path[10] = "/usr/bin/";

	fnctargs->fnct_path_1 = (char *)malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(fnct_1) + 1));
	fnctargs->fnct_path_2 = (char *)malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(fnct_2) + 1));
	ft_strlcpy(fnctargs->fnct_path_1, "/usr/bin/", 10);
	ft_strlcpy(fnctargs->fnct_path_2, "/usr/bin/", 10);
	ft_strlcat(fnctargs->fnct_path_1, fnct_1, (ft_strlen(path) + ft_strlen(fnct_1) + 1));
	ft_strlcat(fnctargs->fnct_path_2, fnct_2, (ft_strlen(path) + ft_strlen(fnct_2) + 1));
}