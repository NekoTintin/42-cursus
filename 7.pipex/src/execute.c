/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:13:45 by qupollet          #+#    #+#             */
/*   Updated: 2024/11/26 16:41:55 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_fileno(int code)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	exit(code);
}

void	ft_failed_execve(char **nargs)
{
	ft_freetab(nargs);
	ft_putendl_fd("execve failed.", 2);
}

int	ft_exec(char *args, char **envp)
{
	char	**nargs;
	char	*prog_path;
	int		error_code;

	nargs = ft_split(args, ' ');
	if (!nargs)
		return (ft_putendl_fd("Split failed", 2), -1);
	prog_path = ft_find_exec_in_envp(nargs[0], envp);
	if (prog_path == NULL)
	{
		ft_putendl_fd("Program not found.", 2);
		return (ft_freetab(nargs), 127);
	}
	ft_check_free(nargs[0]);
	nargs[0] = prog_path;
	if (!nargs[0])
		return (ft_freetab(nargs), -1);
	error_code = ft_checkprog(nargs[0]);
	if (error_code != 0)
		return (ft_freetab(nargs), error_code);
	if (execve(nargs[0], nargs, envp) == -1)
		return (ft_failed_execve(nargs), -1);
	return (0);
}

void	ft_first_child(int *fds, char **envp, char *file, char *args)
{
	int		file_desp;

	ft_close_pipes(fds, 1, 0);
	file_desp = open(file, O_RDONLY);
	if (file_desp < 0)
	{
		ft_close_pipes(fds, 0, 1);
		ft_errors('r');
	}
	if (dup2(file_desp, STDIN_FILENO) < 0)
	{
		close(file_desp);
		ft_close_pipes(fds, 0, 1);
		ft_errors('d');
	}
	if (dup2(fds[1], STDOUT_FILENO) < 0)
	{
		close(file_desp);
		ft_close_pipes(fds, 0, 1);
		ft_errors('d');
	}
	close(file_desp);
	ft_close_pipes(fds, 0, 1);
	if (ft_exec(args, envp) != 0)
		ft_close_fileno(0);
}

void	ft_second_child(int *fd1, char **envp, char *file, char *args)
{
	int		file_desp;
	int		error;

	file_desp = ft_checkfile(file);
	if (file_desp < 0)
	{
		ft_close_pipes(fd1, 1, 1);
		ft_errors('f');
	}
	if (dup2(file_desp, STDOUT_FILENO) == -1)
	{
		ft_close_pipes(fd1, 1, 1);
		close(file_desp);
		ft_errors('d');
	}
	if (dup2(fd1[0], STDIN_FILENO) == -1)
	{
		ft_close_pipes(fd1, 1, 1);
		close(file_desp);
		ft_errors('d');
	}
	close(file_desp);
	ft_close_pipes(fd1, 1, 1);
	error = ft_exec(args, envp);
	ft_close_fileno(error);
}
