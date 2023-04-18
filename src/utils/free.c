/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:49:32 by macote            #+#    #+#             */
/*   Updated: 2023/04/16 17:39:07 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

//Frees everything once shell commands are done executing.
void	free_commands(t_pipex pip)
{
	int	i;
	int	j;

	i = 0;
	while (pip.commands[i])
	{
		j = 0;
		while (pip.commands[i][j])
		{
			free(pip.commands[i][j]);
			j++;
		}
		free(pip.commands[i]);
		i++;
	}
	free(pip.commands);
	free(pip.paths);
	free(pip.infile);
	free(pip.outfile);
}
