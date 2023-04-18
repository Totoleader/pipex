/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:30:52 by macote            #+#    #+#             */
/*   Updated: 2023/04/17 09:55:13 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// check / parse / executes commands && frees
void	pipex(int argc, char **args)
{
	t_pipex	pip;

	check_args(argc, args[1], args[argc - 1]);
	pip.cmd_nb = argc - 3;
	parse_commands(argc, args, &pip.commands, &pip.paths);
	parse_filepaths(argc, args, &pip.infile, &pip.outfile);
	exec_commands(pip);
}

//main
int	main(int argc, char **argv)
{
	pipex(argc, argv);
	return (0);
}
