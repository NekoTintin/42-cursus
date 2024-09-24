/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:06:45 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/24 17:06:49 by NekoTintin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int		ft_is_rect(char **tiles);
static int		ft_map_is_closed(char **tiles);
static int		ft_is_walled(char *line);
static int		ft_is_vwalled(char **tiles, int nb_lines);

char	**ft_map(char *filename)
{
	char	**tiles;

	if (ft_map_is_ber(filename) == -1)
		return (NULL);
	tiles = ft_load_tiles(filename);
	if (!tiles)
		return (NULL);
	if (ft_is_rect(tiles) == -1)
		return (ft_free_chartab(tiles), NULL);
	if (ft_map_is_closed(tiles) == -1)
		return (ft_free_chartab(tiles), NULL);
	if (ft_verify_content(tiles) == -1)
		return (ft_free_chartab(tiles), NULL);
	if (ft_can_be_finished(tiles) == 0)
		return (ft_free_chartab(tiles), NULL);
	return (tiles);
}

static int	ft_is_rect(char **tiles)
{
	int		line_size;
	int		idx;

	idx = 0;
	line_size = ft_strlen(tiles[0]);
	while (tiles[idx])
	{
		if (ft_strlen(tiles[idx]) != line_size)
			return (ft_putendl_fd("Error\nMap is not a rectangle.", 2), -1);
		idx++;
	}
	return (0);
}

static int	ft_map_is_closed(char **tiles)
{
	int		nb_lines;

	if (!tiles || !tiles[0])
		return (-1);
	nb_lines = 0;
	while (tiles[nb_lines])
		nb_lines++;
	if (ft_is_walled(tiles[0]) == -1)
		return (ft_putendl_fd("Error\nMap not closed (Top line).", 2), -1);
	if (ft_is_walled(tiles[nb_lines - 1]) == -1)
		return (ft_putendl_fd("Error\nMap not closed (Bottom line).", 2), -1);
	if (ft_is_vwalled(tiles, nb_lines) == -1)
		return (ft_putendl_fd("Error\nMap not closed (Sides lines).", 2), -1);
	return (0);
}

static int	ft_is_walled(char *line)
{
	int		idx;

	idx = 0;
	while (line[idx])
	{
		if (line[idx] != '1')
			return (-1);
		idx++;
	}
	return (0);
}

static int	ft_is_vwalled(char **tiles, int nb_lines)
{
	int		size;
	int		idx;

	idx = 0;
	size = ft_strlen(tiles[0]);
	while (idx < nb_lines)
	{
		if (tiles[idx][0] != '1' || tiles[idx][size - 1] != '1')
			return (-1);
		idx++;
	}
	return (0);
}
