/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:59:53 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/24 17:06:51 by NekoTintin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_backtracking(char **map, int x, int y, char **visited);

static int	ft_get_number(char **tiles, char c)
{
	int		idx;
	int		j;
	int		counter;

	idx = 0;
	counter = 0;
	while (tiles[idx] != NULL)
	{
		j = 0;
		while (tiles[idx][j] != '\0')
		{
			if (tiles[idx][j] == c)
				counter++;
			j++;
		}
		idx++;
	}
	return (counter);
}

int	ft_verify_content(char **tiles)
{
	int		player;
	int		collec;
	int		exit;

	player = ft_get_number(tiles, 'P');
	collec = ft_get_number(tiles, 'C');
	exit = ft_get_number(tiles, 'E');
	if (player != 1)
		return (ft_putendl_fd("Error\nInvalid number of player.", 2), -1);
	if (collec < 1)
		return (ft_putendl_fd("Error\nMap need 1 collectible.", 2), -1);
	if (exit != 1)
		return (ft_putendl_fd("Error\nInvalid number of exit.", 2), -1);
	return (0);
}

int	ft_map_is_ber(char *filepath)
{
	char	*ext;
	int		size;
	int		fd;

	size = ft_strlen(filepath);
	if (size < 4)
		return (ft_putendl_fd("Error\nMap is not a .ber file.", 2), -1);
	ext = filepath + size - 4;
	if (ft_strncmp(ext, ".ber", 4) != 0)
		return (ft_putendl_fd("Error\nMap is not a .ber file.", 2), -1);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error\nCannot open file, does the file exists ?",
				2), -1);
	close(fd);
	return (0);
}

int	ft_can_be_finished(char **tiles)
{
	char	**visited;
	int		x;
	int		y;
	int		res;

	x = 0;
	y = 0;
	ft_get_map_size(tiles, &x, &y);
	visited = ft_tabdup(tiles);
	if (visited == NULL)
		return (ft_free_chartab(visited), 0);
	ft_get_player_pos(tiles, &x, &y);
	res = ft_backtracking(tiles, x, y, visited);
	if (res == 0)
		ft_putendl_fd("Error\nMap cannot be finished.", 2);
	ft_free_chartab(visited);
	return (res);
}

int	ft_backtracking(char **map, int x, int y, char **visited)
{
	if (map[y][x] == '1' || visited[y][x] == 'V')
		return (0);
	visited[y][x] = 'V';
	if (ft_backtracking(map, x, y - 1, visited)
		|| ft_backtracking(map, x - 1, y, visited)
		|| ft_backtracking(map, x, y + 1, visited)
		|| ft_backtracking(map, x + 1, y, visited))
		return (1);
	if (ft_is_exit_v(visited) && ft_get_nb_collec(visited) == 0)
		return (1);
	return (0);
}
