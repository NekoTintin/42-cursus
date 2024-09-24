/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:02:48 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/24 17:06:55 by NekoTintin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_get_player_pos(char **map, int *x, int *y)
{
	int	idx;
	int	idy;

	idy = 0;
	while (map[idy] != NULL)
	{
		idx = 0;
		while (map[idy][idx] != '\0')
		{
			if (map[idy][idx] == 'P')
			{
				*x = idx;
				*y = idy;
				return ;
			}
			idx++;
		}
		idy++;
	}
}

void	ft_get_exit_pos(t_env *game, int *x, int *y)
{
	int	idx;
	int	idy;

	idy = 0;
	while (game->map[idy] != NULL)
	{
		idx = 0;
		while (game->map[idy][idx] != '\0')
		{
			if (game->map[idy][idx] == 'E')
			{
				*x = idx;
				*y = idy;
				return ;
			}
			idx++;
		}
		idy++;
	}
}

int	ft_get_nb_collec(char **map)
{
	int		collec;
	int		idx;
	int		idy;

	collec = 0;
	idy = 0;
	while (map[idy])
	{
		idx = 0;
		while (map[idy][idx] != '\0')
		{
			if (map[idy][idx] == 'C')
				collec++;
			idx++;
		}
		idy++;
	}
	return (collec);
}

void	ft_get_map_size(char **map, int *x, int *y)
{
	int		map_x;
	int		map_y;

	map_x = 0;
	map_y = 0;
	while (map[map_y] != NULL)
		map_y++;
	if (map[0] != NULL)
	{
		while (map[0][map_x] != '\0')
			map_x++;
	}
	*x = map_x;
	*y = map_y;
}

char	**ft_tabdup(char **str)
{
	char	**nstr;
	int		size;
	int		idx;

	size = 0;
	idx = -1;
	while (str[++idx])
		size++;
	nstr = ft_calloc((size + 1), sizeof(char *));
	if (!nstr)
		return (NULL);
	idx = -1;
	while (++idx < size)
	{
		nstr[idx] = ft_strdup(str[idx]);
		if (!nstr[idx])
			return (ft_free_chartab(nstr), NULL);
	}
	return (nstr);
}
