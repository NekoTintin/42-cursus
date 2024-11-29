/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:34:31 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/24 16:57:24 by NekoTintin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_from_file(int fd, char *stash, char *buf)
{
	char	*tmp;
	int		nb_char;

	nb_char = 1;
	while (!ft_strchr(stash, '\n') && nb_char > 0)
	{
		nb_char = read(fd, buf, BUFFER_SIZE);
		if (nb_char == -1)
		{
			free(stash);
			return (NULL);
		}
		buf[nb_char] = 0;
		tmp = ft_strjoin(stash, buf);
		free(stash);
		if (!tmp)
			return (NULL);
		stash = tmp;
	}
	return (stash);
}

char	*ft_get_line(char *stash)
{
	size_t		idx;
	size_t		size;
	char		*fstring;

	idx = 0;
	while (stash[idx] != '\n' && stash[idx] != 0)
		idx++;
	if (stash[idx] == '\n')
		idx++;
	size = idx;
	fstring = malloc(sizeof(char) * (size + 1));
	if (!fstring)
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		fstring[idx] = stash[idx];
		idx++;
	}
	fstring[idx] = 0;
	return (fstring);
}

char	*ft_remove_before_nl(char **stash)
{
	size_t		idx;
	size_t		size;
	char		*tmp;

	if (!stash || !*stash)
		return (NULL);
	idx = 0;
	size = ft_strlen(*stash);
	while ((*stash)[idx] != '\n' && (*stash)[idx] != 0)
		idx++;
	if ((*stash)[idx] == '\n')
		idx++;
	tmp = ft_substr(*stash, idx, size - idx);
	if (!tmp)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	free(*stash);
	*stash = tmp;
	return (*stash);
}

int	ft_init(char **stash, char **buf)
{
	if (!*stash)
	{
		*stash = ft_strdup("");
		if (!*stash)
			return (-1);
	}
	*buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buf)
	{
		free(*stash);
		*stash = NULL;
		return (-1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*stash[4096];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_init(&stash[fd], &buf) == -1)
		return (NULL);
	stash[fd] = ft_read_from_file(fd, stash[fd], buf);
	free(buf);
	if (!stash[fd])
		return (NULL);
	line = ft_get_line(stash[fd]);
	if (!line || line[0] == '\0')
	{
		free(line);
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = ft_remove_before_nl(&stash[fd]);
	if (!stash[fd])
		return (free(line), NULL);
	return (line);
}
