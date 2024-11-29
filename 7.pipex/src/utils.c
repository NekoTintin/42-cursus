/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:07:48 by qupollet          #+#    #+#             */
/*   Updated: 2024/11/26 16:04:53 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_freetab(char **args)
{
	int	idx;

	idx = -1;
	while (args[++idx] != NULL)
		free(args[idx]);
	free(args);
}

void	ft_check_free(char *arg)
{
	if (arg == NULL)
		return ;
	else
	{
		free(arg);
		arg = NULL;
	}
}

void	ft_close_pipes(int *fds, int pread, int pwrite)
{
	if (fds)
	{
		if (pread == 1 && fds[0] >= 0)
			close(fds[0]);
		if (pwrite == 1 && fds[1] >= 0)
			close(fds[1]);
	}
}

int	ft_is_absolute(char *path)
{
	if (ft_strchr(path, '/'))
		return (1);
	return (0);
}

void	ft_errors(char mode)
{
	if (mode == 'c')
		perror("Failed to create a child process");
	else if (mode == 'p')
		perror("Failed to create a pipe");
	else if (mode == 'w')
		perror("Failed to wait child");
	else if (mode == 'd')
		perror("Failed to dup2");
	else if (mode == 'r')
		perror("Failed read file");
	else if (mode == 'f')
		perror("Failed write in file");
	exit(EXIT_FAILURE);
}
