/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:29:57 by qupollet          #+#    #+#             */
/*   Updated: 2024/11/26 13:08:24 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include "../libft/libft.h"

# include <unistd.h>
# include <stdlib.h>  
# include <stdio.h> 
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

int			ft_printf(const char *str, ...);

// Prototypes for execute.c
void		ft_first_child(int *fds, char **envp, char *file, char *args);
void		ft_second_child(int *fd1, char **envp, char *file, char *args);

// Prototypes for file_permission.c
int			ft_checkfile(char *file);
int			ft_checkprog(char *prog);
int			ft_close_fail_cmd2(char *prog);

// Prototypes in utils.c
void		ft_freetab(char **args);
void		ft_check_free(char *arg);
void		ft_close_pipes(int *fds, int pread, int pwrite);
void		ft_errors(char mode);
int			ft_is_absolute(char *path);

// Prototypes for find_exec.c
char		*ft_find_exec_in_envp(char	*prog, char **envp);
#endif
