/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:13:47 by macote            #+#    #+#             */
/*   Updated: 2023/04/18 09:35:48 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_args2(char **arg)
{
	int		i;
	char	quote;

	i = 0;
	while ((*arg)[i])
	{
		if (((*arg)[i] == '\'' || (*arg)[i] == '\"') && ft_strchr((*arg) + i
				+ 1, (*arg)[i]))
		{
			quote = (*arg)[i];
			(*arg)[i++] = ' ';
			while ((*arg)[i] != quote)
			{
				if ((*arg)[i] == ' ')
					(*arg)[i] = '	';
				i++;
			}
			(*arg)[i] = ' ';
		}
		i++;
	}
}

//parses all the commands and flags into a single array
void	parse_commands(int argc, char **args, char ****commands, char ***paths)
{
	int	i;
	int	j;

	*commands = ft_calloc(argc - 2, sizeof(**commands));
	if (!(*commands))
	{
		exit(EXIT_FAILURE);
	}
	*paths = ft_calloc(argc - 2, sizeof(**paths));
	if (!(*commands))
	{
		free(*commands);
		exit(EXIT_FAILURE);
	}
	i = 2;
	j = 0;
	while (i < argc - 1)
	{
		check_args2(&args[i]);
		(*commands)[j] = ft_split(args[i++], ' ');
		(*paths)[j] = find_path((*commands)[j][0]);
		free((*commands)[j][0]);
		(*commands)[j][0] = (*paths)[j];
		j++;
	}
}

//parses the infile and outfile paths
void	parse_filepaths(int argc, char **args, char **infile, char **outfile)
{
	*infile = ft_strdup(args[1]);
	*outfile = ft_strdup(args[argc - 1]);
}
