/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_check2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:28:12 by macote            #+#    #+#             */
/*   Updated: 2023/04/17 11:01:30 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

//Every function in this section are just
//normal c functions with added error handling.
int	open_r(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("open failed");
		exit(EXIT_SUCCESS);
	}
	return (fd);
}

int	open_w(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_TRUNC);
	if (fd == -1)
	{
		perror("open failed");
		exit(EXIT_SUCCESS);
	}
	return (fd);
}

//Checks if the number of args is at least 4
//and if the infile and outfile are valid.
void	check_args(int argc, char *infile, char *outfile)
{
	int	fd;

	if (argc < 5)
	{
		perror("not enough args");
		exit(EXIT_FAILURE);
	}
	if (access(infile, R_OK) == -1 || access(outfile, W_OK) == -1)
	{
		perror("permissions failed");
		exit(EXIT_SUCCESS);
	}
	fd = open(outfile, O_TRUNC);
	close(fd);
}
