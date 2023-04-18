/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:07:25 by macote            #+#    #+#             */
/*   Updated: 2023/04/17 11:01:11 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

//gets the text from the pipe and puts it into a string
char	*get_text(int fd)
{
	char	buffer[1];
	char	*string;
	int		read_check;

	string = NULL;
	read_check = read(fd, buffer, 1);
	if (!read_check)
		perror("command not found");
	while (read_check > 0)
	{
		string = ft_strjoin(string, buffer, 1);
		read_check = read(fd, buffer, 1);
	}
	return (string);
}

//gets the path of a command with the "whereis" shell command
static char	*raw_path(char *cmd)
{
	int		fd[2];
	int		pid;
	char	*whereis_args[3];
	char	*path;

	pipe(fd);
	pid = fork();
	whereis_args[0] = "whereis";
	whereis_args[1] = cmd;
	whereis_args[2] = NULL;
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		execve("/usr/bin/whereis", whereis_args, NULL);
	}
	waitpid(pid, NULL, 0);
	close(fd[1]);
	path = get_text(fd[0]);
	close(fd[0]);
	return (path);
}

//trims the \n at the end of the output of "raw_path()"
static char	*trim_path(char *path)
{
	int		i;
	int		len;
	char	*trimmed_path;

	if (!path)
		return (NULL);
	len = 0;
	while (path[len] && path[len] != '\n')
		len++;
	trimmed_path = calloc(sizeof(char), len + 1);
	if (!trimmed_path)
		return (NULL);
	i = 0;
	while (i < len)
	{
		trimmed_path[i] = path[i];
		i++;
	}
	free(path);
	return (trimmed_path);
}

//main pathfinding function
char	*find_path(char *path)
{
	return (trim_path(raw_path(path)));
}
