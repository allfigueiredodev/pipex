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

void set_fctn_data(t_fctn *fctn)
{
	int i;

	i = 0;
	fctn->fctn_path = (char **)ft_calloc(fctn->total_pipes + 1, sizeof(char **));
	while(i < fctn->total_pipes)
	{
		fctn->fctn_path[i] = (char *)malloc(sizeof(char) * (ft_strlen(BIN_PATH) + ft_strlen(fctn->fctns[i][0]) + 1));
		ft_strlcpy(fctn->fctn_path[i], BIN_PATH, 10);
		ft_strlcat(fctn->fctn_path[i], fctn->fctns[i][0], (ft_strlen(BIN_PATH)) + ft_strlen(fctn->fctns[i][0]) + 1);
		i++;
	}
	fctn->fctn_path[i] = NULL;
}

// int main(void)
// {
// 	t_fctn fctn;

// 	char *fctns[] = {
//  		"./a.out",
// 		"./lista1",
// 		"sort",
//  		"ls -l",
//  		"grep working",
// 		"./lista2"
// 	};
// 	fctn.total_pipes = 3;
// 	argv_filter(&fctn, fctns);
// 	set_fctn_data(&fctn);
// }
