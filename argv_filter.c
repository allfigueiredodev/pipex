/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_filter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:55:44 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/07 20:02:44 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	int	ft_btw(char const *s, char c)
{
	int			counter;
	char const	*ptr;
	int			i;

	ptr = s;
	if (*(ptr + 0) == c)
		i = 1;
	else
		i = 0;
	counter = 0;
	while (*(ptr + i))
	{
		if (*(ptr + i) == c)
		{
			return (counter);
		}
		counter ++;
		i++;
	}
	return (counter);
}

void	argv_filter(t_fctn *fctn, char **argv, int argc)
{
	int i;
	int total_args;

	i = 0;
	total_args = sizeof(argv) / sizeof(argv[0]);
	*fctn->fctns = (char**)malloc(sizeof(char**) * (total_args - 3));
	while(i < (total_args - 3))
	{
		fctn->fctns[i] = (char *)ft_calloc((ft_btw(argv[i], " ") + 1), sizeof(char *));
		i++;
	}
	while (j > 0)
	{
		(*map_copy)[i] = ft_calloc((x + 1), sizeof(char));
		gnl_strlcpy((*map_copy)[i], map[i], x + 1);
		j--;
		i++;
	}
}

int main(void)
{
	t_fctn *test;
	
	char *fctns[] = {
		"sort",
		"ls -l",
		"grep working",
		"wc -l"
	};
	argv_filter(&test, fctns, 5);
}