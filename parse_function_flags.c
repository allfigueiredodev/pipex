/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_function_flags.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:28:08 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/01 16:23:56 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void parse_function_flags(char *args_1, char *args_2, t_fnctargs *fnctargs)
{
	char **parsed_args_1;
	char **parsed_args_2;
	
	parsed_args_1 = ft_split(args_1, ' ');
	parsed_args_2 = ft_split(args_2, ' ');
	fnctargs->fnct_1 = parsed_args_1[0];
	fnctargs->fnctargs_1 = parsed_args_1;
	fnctargs->fnct_2 = parsed_args_2[0];
	fnctargs->fnctargs_2 = parsed_args_2;
}

// int main(void)
// {
// 	t_fnctargs fnctargs;
// 	parse_function_flags("printf hello world NULL", "cat -e NULL", &fnctargs);
// 	printf("function 1: %s\n", fnctargs.fnct_1);
// 	printf("function 1: %s\n", fnctargs.fnctargs_1);
// 	printf("function 2: %s\n", fnctargs.fnct_2);
// 	printf("function 2: %s\n", fnctargs.fnctargs_2);
// 	return (0);
// }