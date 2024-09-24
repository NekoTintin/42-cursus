/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:05:51 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/17 16:48:58 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	ft_what_to_render(t_env *game, int x, int y)
{
	if (game->map[y][x] == '0' || game->map[y][x] == 'P'
		|| game->map[y][x] == 'C' || game->map[y][x] == 'E')
		mlx_put_image_to_window(game->ptr, game->win, game->txt->ground,
			(TILE_SIZE * x), (TILE_SIZE * y));
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->ptr, game->win, game->txt->wall,
			(TILE_SIZE * x), (TILE_SIZE * y));
	return (0);
}

void	ft_render_map(t_env *game)
{
	int		x;
	int		y;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (ft_what_to_render(game, x, y) == -1)
				return (ft_putendl_fd("wtr", 2));
			x++;
		}
		y++;
	}
}
