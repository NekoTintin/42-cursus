/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:25:50 by qupollet          #+#    #+#             */
/*   Updated: 2024/11/26 16:16:55 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_checkfile(char *file)
{
	int		fd;

	if (access(file, F_OK) == -1)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0744);
		if (fd == -1)
			return (-1);
	}
	else if (access(file, W_OK) == -1)
	{
		return (-1);
	}
	else
	{
		fd = open(file, O_WRONLY | O_TRUNC);
		if (fd == -1)
			return (-1);
	}
	return (fd);
}

int	ft_checkprog(char *prog)
{
	if (prog == NULL)
		return (-1);
	if (access(prog, F_OK) != 0)
	{
		ft_putendl_fd("Program not found", 2);
		return (127);
	}
	if (access(prog, X_OK) != 0)
	{
		ft_putendl_fd("No execute permission for the program", 2);
		return (126);
	}
	return (0);
}
