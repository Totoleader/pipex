/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:41:03 by macote            #+#    #+#             */
/*   Updated: 2023/04/17 11:00:53 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

//Every function in this section are just
//normal c functions with added error handling.
void	dup2_(int fd, int std)
{
	if (dup2(fd, std) == -1)
	{
		perror("dup2 failed");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

int	fork_(t_pipex pip)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		free_commands(pip);
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	execve_(char *path, char **command)
{
	if (!path)
		exit(EXIT_FAILURE);
	if (execve(path, command, NULL) == -1)
	{
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}

void	pipe_(int *fd, t_pipex pip)
{
	if (pipe(fd) == -1)
	{
		free_commands(pip);
		perror("pipe failed");
		exit(EXIT_FAILURE);
	}
}
