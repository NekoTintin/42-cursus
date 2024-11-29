/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:44:46 by qupollet          #+#    #+#             */
/*   Updated: 2024/11/26 16:01:27 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_verif_args(int argc, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd("Error, pipex need 4 arguments.\n", 2);
		ft_putstr_fd("./pipex infile 'cmd1' 'cmd2' outfile\n", 2);
		exit(EXIT_FAILURE);
	}
	if (envp == NULL || envp[0] == NULL)
	{
		ft_putendl_fd("Program not found.", 2);
		exit (127);
	}
}

void	ft_fork_error(int *fds)
{
	ft_close_pipes(fds, 1, 1);
	ft_errors('f');
}

int	main(int argc, char **argv, char **envp)
{
	pid_t		child1;
	pid_t		child2;
	int			fds[2];
	int			status;

	ft_verif_args(argc, envp);
	if (pipe(fds) == -1)
		ft_errors('p');
	child1 = fork();
	if (child1 < 0)
		ft_fork_error(fds);
	if (child1 == 0)
		ft_first_child(fds, envp, argv[1], argv[2]);
	child2 = fork();
	if (child2 < 0)
		ft_fork_error(fds);
	if (child2 == 0)
		ft_second_child(fds, envp, argv[4], argv[3]);
	ft_close_pipes(fds, 1, 1);
	if (waitpid(child1, &status, 0) < 0)
		return (WEXITSTATUS(status));
	if (waitpid(child2, &status, 0) < 0)
		return (WEXITSTATUS(status));
	return (WEXITSTATUS(status));
}
