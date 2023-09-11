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

static size_t	ft_del_count(char const *s, char c)
{
	size_t		counter;
	char const	*ptr;
	int			i;

	ptr = s;
	counter = 0;
	i = 0;
	while (*(ptr + i))
	{
		while (*(ptr + i) == c && *(ptr + i) != '\0')
			i++;
		while (*(ptr + i) != c && *(ptr + i) != '\0')
			i++;
		if (*(ptr + i) != '\0' || *(ptr + i - 1) != c)
			counter++;
	}
	return (counter);
}

void	argv_filter(t_fctn *fctn, char **argv)
{
	int i;
	int j;
	int total_args;

	i = 0;
	j = 2;
	fctn->fctns = (char***)ft_calloc((fctn->total_pipes) + 1, sizeof(char***));
	while(i < (fctn->total_pipes))
	{
		total_args  = ft_del_count(argv[j], 32);
		fctn->fctns[i] = ft_split(argv[j], 32);
		fctn->fctns[i][total_args] = NULL;
		i++;
		j++;
	}
	fctn->fctns[fctn->total_pipes] = NULL;
}

// int main(void)
// {
//  	t_fctn fctn;
	
// 	fctn.total_pipes = 3;
//  	char *fctns[] = {
//  		"./a.out",
// 		"./lista1",
// 		"sort",
//  		"ls -l",
//  		"grep working",
// 		"./lista2"
// 	};
// 	argv_filter(&fctn, fctns);
// }