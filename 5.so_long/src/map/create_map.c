/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:50:39 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/24 17:06:47 by NekoTintin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_get_nb_lines(int filefd);
static int	ft_check_valid_char(char **tiles);

static char	**ft_create_tiles(int fd, int nb_lines)
{
	char		**tiles;
	char		*res;
	int			idx;

	idx = 0;
	tiles = ft_calloc((nb_lines + 1), sizeof(char *));
	if (!tiles)
		return (NULL);
	res = get_next_line(fd);
	while (res != NULL)
	{
		if (res[0] == '?')
		{
			free(res);
			return (ft_free_chartab(tiles), NULL);
		}
		tiles[idx] = ft_strdup(res);
		free(res);
		if (!tiles[idx])
			return (ft_free_chartab(tiles), NULL);
		idx++;
		res = get_next_line(fd);
	}
	return (tiles);
}

char	**ft_load_tiles(char *filepath)
{
	char	**tiles;
	int		filefd;
	int		nb_lines;

	filefd = open(filepath, O_RDONLY);
	if (filefd < 0)
		return (NULL);
	nb_lines = ft_get_nb_lines(filefd);
	close(filefd);
	filefd = open(filepath, O_RDONLY);
	if (filefd < 0)
		return (NULL);
	tiles = ft_create_tiles(filefd, nb_lines);
	close(filefd);
	if (!tiles || !tiles[0])
		return (ft_free_chartab(tiles), NULL);
	if (ft_check_valid_char(tiles) == -1)
	{
		ft_putendl_fd("Error\nMap contains an invalid character.", 2);
		return (ft_free_chartab(tiles), NULL);
	}
	return (tiles);
}

static int	ft_get_nb_lines(int filefd)
{
	int			nb;
	char		*res;

	nb = 0;
	res = get_next_line(filefd);
	while (res != NULL)
	{
		if (res[0] == '?')
		{
			free(res);
			return (ft_putendl_fd("Error\nCannot reading the file.", 2), -1);
		}
		nb++;
		free(res);
		res = get_next_line(filefd);
	}
	if (res)
		free(res);
	return (nb);
}

int	ft_check_valid_char(char **tiles)
{
	int		y;
	int		x;

	y = 0;
	while (tiles[y])
	{
		x = 0;
		while (tiles[y][x] != '\0')
		{
			if (tiles[y][x] != '0' && tiles[y][x] != '1' && tiles[y][x] != 'P'
					&& tiles[y][x] != 'C' && tiles[y][x] != 'E')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}
