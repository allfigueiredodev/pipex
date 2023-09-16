/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fctn_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:09:58 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/16 01:43:23 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*right_access(char **all_possible_paths)
{
	int		i;
	char	*temp;

	i = 0;
	while (all_possible_paths[i])
	{
		if (access(all_possible_paths[i], F_OK) == 0
			&& access(all_possible_paths[i], X_OK) == 0)
		{			
			temp = ft_strdup(all_possible_paths[i]);
			free_envps_array(all_possible_paths);
			return (temp);
		}
		else
		{
			i++;
		}
	}
	free_envps_array(all_possible_paths);
	return (NULL);
}

char	**set_fctn_data(char *fct, char **envp)
{
	char	*env_path;
	char	**all_possible_paths;
	int		i;
	// char	*temp;

	all_possible_paths = NULL;
	i = 0;
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH=", 5))
		{
			env_path = ft_strtrim(ft_strnstr(*envp, "PATH=", 5), "PATH=");
			all_possible_paths = ft_split(env_path, ':');
			while (all_possible_paths[i])
			{
				// temp = all_possible_paths[i];
				all_possible_paths[i] = gnl_strjoin(all_possible_paths[i], "/");
				// free(temp);
				// temp = all_possible_paths[i];
				all_possible_paths[i] = gnl_strjoin(all_possible_paths[i], fct);
				// free(temp);
				i++;
			}
			free(env_path);
			return (all_possible_paths);
		}
		envp++;
	}
	return (all_possible_paths);
}

void	fctn_path_validator(t_fctn *fctn, char **envp)
{
	int	i;

	i = 0;
	fctn->fctn_path = (char **)ft_calloc(fctn->total_pipes + 1, sizeof(char *));
	fctn->fctn_path[fctn->total_pipes] = NULL;
	i = 0;
	while (fctn->fctns[i])
	{
		fctn->fctn_path[i] = right_access(
				set_fctn_data(fctn->fctns[i][0], envp));
		if (fctn->fctn_path[i] == NULL)
		{
			ft_putstr_fd("command not found: ", 2);
			ft_putstr_fd(fctn->fctns[i][0], 2);
			ft_putstr_fd("\n", 2);
			exit(1);
		}
		i++;
	}
}

void	env_path_validator(t_fctn *fctn, char **envp)
{
	fctn_path_validator(fctn, envp);
}
