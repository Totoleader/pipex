/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:17:36 by macote            #+#    #+#             */
/*   Updated: 2023/04/17 10:54:37 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <libc.h>
# include <stdio.h>
# include <unistd.h>

typedef struct pipex
{
	char	*infile;
	char	*outfile;
	char	***commands;
	char	**paths;
	int		cmd_nb;
}			t_pipex;

char		*find_path(char *path);
char		*get_text(int fd);
void		parse_commands(int argc, char **args, char ****commands,
				char ***paths);
void		free_commands(t_pipex pip);
void		parse_filepaths(int argc, char **args, char **infile,
				char **outfile);
void		dup2_(int fd, int std);
int			fork_(t_pipex pip);
void		execve_(char *path, char **command);
void		pipe_(int *fd, t_pipex pip);
void		check_args(int argc, char *infile, char *outfile);
int			open_r(char *file);
int			open_w(char *file);
void		exec_first_command(t_pipex pip, int *fd, int infile_fd);
void		exec_middle_commands(t_pipex pip, int *fd);
void		exec_last_command(t_pipex pip, int *fd, int outfile_fd);
void		exec_commands(t_pipex pip);

#endif
