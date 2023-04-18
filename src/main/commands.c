/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:19:57 by macote            #+#    #+#             */
/*   Updated: 2023/04/17 12:04:42 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

//first shell command that takes in the infile
void	exec_first_command(t_pipex pip, int *fd, int infile_fd)
{
	int	pid;

	pipe_(fd, pip);
	pid = fork_(pip);
	if (pid == 0)
	{
		close(fd[0]);
		dup2_(fd[1], STDOUT_FILENO);
		dup2_(infile_fd, STDIN_FILENO);
		execve_(pip.paths[0], pip.commands[0]);
	}
	close(fd[1]);
	close(infile_fd);
	waitpid(pid, NULL, 0);
}

//every shell commands that is not first or last
void	exec_middle_commands(t_pipex pip, int *fd)
{
	int	pid;
	int	previous_pipe;
	int	i;

	i = 0;
	while (++i != pip.cmd_nb - 1)
	{
		previous_pipe = fd[0];
		pipe_(fd, pip);
		pid = fork_(pip);
		if (pid == 0)
		{
			close(fd[0]);
			dup2_(fd[1], STDOUT_FILENO);
			dup2_(previous_pipe, STDIN_FILENO);
			execve_(pip.paths[i], pip.commands[i]);
		}
		close(fd[1]);
		close(previous_pipe);
		waitpid(pid, NULL, 0);
	}
}

//last shell command that outputs to outfile
void	exec_last_command(t_pipex pip, int *fd, int outfile_fd)
{
	int	pid;

	pid = fork_(pip);
	if (pid == 0)
	{
		dup2_(fd[0], STDIN_FILENO);
		dup2_(outfile_fd, STDOUT_FILENO);
		execve_(pip.paths[pip.cmd_nb - 1], pip.commands[pip.cmd_nb - 1]);
	}
	close(fd[0]);
	close(outfile_fd);
	waitpid(pid, NULL, 0);
}

//main commands function
void	exec_commands(t_pipex pip)
{
	int	fd[2];
	int	infile_fd;
	int	outfile_fd;

	infile_fd = open(pip.infile, O_RDONLY);
	outfile_fd = open(pip.outfile, O_WRONLY | O_TRUNC);
	exec_first_command(pip, fd, infile_fd);
	exec_middle_commands(pip, fd);
	exec_last_command(pip, fd, outfile_fd);
	free_commands(pip);
}
