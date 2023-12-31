/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:43:25 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/16 05:44:09 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	chmod_check_file_a(char **argv)
{
	if (access(argv[1], F_OK) == 0)
	{
		if (access(argv[1], R_OK) == 0)
			return (1);
		else
		{
			ft_putstr_fd("permission denied: ", 2);
			ft_putstr_fd(argv[1], 2);
			ft_putstr_fd("\n", 2);
		}
	}
	else
	{
		ft_putstr_fd("no such file or directory: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd("\n", 2);
	}
	return (0);
}

int	chmod_check_file_b(int argc, char **argv)
{
	if (access(argv[argc - 1], F_OK) == 0 || access(argv[argc -1], F_OK) < 0)
	{
		if (access(argv[argc - 1], R_OK) == 0
			&& access(argv[argc - 1], W_OK) == 0
			&& access(argv[argc - 1], F_OK) == 0)
			return (1);
		else if ((access(argv[argc - 1], R_OK) < 0
				|| access(argv[argc - 1], W_OK) < 0)
			&& access(argv[argc - 1], F_OK) == 0)
		{
			ft_putstr_fd("permission denied: ", 2);
			ft_putstr_fd(argv[argc -1], 2);
			ft_putstr_fd("\n", 2);
			return (0);
		}
	}
	return (1);
}

int	chmod_check(int argc, char **argv)
{
	if (!chmod_check_file_a(argv) || !chmod_check_file_b(argc, argv))
		return (0);
	else
	{
		ft_printf("Files found\n");
		ft_printf("All rights granted\n");
		return (1);
	}
}
