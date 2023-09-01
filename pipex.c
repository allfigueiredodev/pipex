/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:49:58 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/31 21:33:06 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
	t_fnctargs fnctargs;
	
	if(argc < 5)
	{
		printf("Not enough arguments\n");
		return (0);
	}
	if(!path_chmod_check(argv[1]))
		return(0);
	parse_function_flags(argv[2], argv[3], &fnctargs);	
	set_fnct_path(fnctargs.fnct_1, fnctargs.fnct_2, &fnctargs);
	printf("%s\n", fnctargs.fnct_1);
	printf("%s\n", fnctargs.fnct_path_1);
	// execve("")	
	return(0);
}