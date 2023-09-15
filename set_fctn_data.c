/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fctn_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:09:58 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/15 01:10:52 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *right_access(char **all_possible_paths)
{
	int i;
	int j;
	
	i = 0;
	j = 1;
	while(all_possible_paths[i])
	{
		if(access(all_possible_paths[i], F_OK) == 0 
		&& access(all_possible_paths[i], X_OK) == 0)
		{
			while(all_possible_paths[i + j])
			{
				free(all_possible_paths[i + j]);
				all_possible_paths[i + j] = NULL;
				j++;
			}
			return(all_possible_paths[i]);
		}
		else
		{
			free(all_possible_paths[i]);
			all_possible_paths[i] = NULL;
			i++;
		}
	}
	free(all_possible_paths);
	all_possible_paths = NULL;
	return(NULL);
}

char **set_fctn_data(char *fctn, char **envp)
{
	char *env_path;
	char **all_possible_paths;
	int i;
	
	all_possible_paths = NULL;
	i = 0;
	while(*envp)
	{
		if(ft_strnstr(*envp, "PATH=", 5))
		{
			env_path = ft_strtrim(ft_strnstr(*envp, "PATH=", 5), "PATH=");
			all_possible_paths = ft_split(env_path, ':'); 
			while(all_possible_paths[i])
			{
				all_possible_paths[i] = gnl_strjoin(all_possible_paths[i], "/");
				ft_strlcat(all_possible_paths[i], fctn, ft_strlen(all_possible_paths[i]) + ft_strlen(fctn) + 1);
				i++;
			}
			free(env_path);
			return(all_possible_paths);
		}
		envp++;
	}
	return(all_possible_paths);
}

void fctn_path_validator(t_fctn *fctn, char **envp)
{
	int i;

	i = 0;
	fctn->fctn_path = (char **)ft_calloc(fctn->total_pipes, sizeof(char **));
	while(i < fctn->total_pipes)
	{
		fctn->fctn_path[i] = ft_calloc(1, sizeof(char *));
		i++;
	}
	fctn->fctn_path[i] = NULL;
	i = 0;
	while(fctn->fctns[i])
	{
		fctn->fctn_path[i] = right_access(set_fctn_data(fctn->fctns[i][0], envp));
		if(fctn->fctn_path[i] == NULL)
		{
			ft_putstr_fd("command not found: ", 2);
			ft_putstr_fd(fctn->fctns[i][0], 2);
			ft_putstr_fd("\n", 2);
			exit(1);
		}
		i++;
	}
}

void env_path_validator(t_fctn *fctn, char **envp)
{
	int i;

	i = 0;
	while(fctn->fctns[i])
	{
		fctn_path_validator(fctn, envp);
		i++;
	}
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_fctn fctn;
	fctn.total_pipes = 3;
	char *arr[] = {"./pipex", "./file_1", "sort", "grep pipex", "wc -l", "./file_2"};
	argv_filter(&fctn, arr);	
	env_path_validator(&fctn, envp);
	while(*fctn.fctn_path)
	{
		printf("%s\n", *fctn.fctn_path);
		fctn.fctn_path++;
	}
	free_all_data(&fctn);
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
// 	free_args(&fctn);
// 	free_fctn_data(&fctn);
// }
