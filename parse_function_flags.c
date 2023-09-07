/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_function_flags.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:28:08 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/07 19:15:50 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void parse_function_flags(t_fctn *fctn, int argc)
{
	char ***all_args;
	// char **parsed_args_2;
	
	parsed_args_1 = ft_split(args_1, ' ');
	parsed_args_2 = ft_split(args_2, ' ');
	fctn->fctn_1 = parsed_args_1[0];
	fctn->fctn_1 = parsed_args_1;
	fctn->fctn_2 = parsed_args_2[0];
	fctn->fctn_2 = parsed_args_2;
}
