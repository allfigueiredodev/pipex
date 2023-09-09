/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fnct_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:09:58 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/07 19:15:50 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void set_fctn_data(char *fctn, int argc)
{
	char path[10] = "/usr/bin/";

	fctn->fctn_path_1 = (char *)malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(fctn_1) + 1));
	ft_strlcpy(fctn->fctn_path_1, "/usr/bin/", 10);
	ft_strlcat(fctn->fctn_path_1, fctn_1, (ft_strlen(path) + ft_strlen(fctn_1) + 1));
}