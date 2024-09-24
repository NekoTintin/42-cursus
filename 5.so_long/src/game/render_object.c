/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:10:23 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/24 17:06:42 by NekoTintin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	ft_what_to_render(t_env *game, int x, int y)
{
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->ptr, game->win, game->txt->cookie,
			(TILE_SIZE * x), (TILE_SIZE * y));
	mlx_put_image_to_window(game->ptr, game->win, game->txt->perso,
		(TILE_SIZE * game->player_x), (TILE_SIZE * game->player_y));
	if (game->collec == 0)
		mlx_put_image_to_window(game->ptr, game->win, game->txt->exit,
			game->exit_x * TILE_SIZE, game->exit_y * TILE_SIZE);
	return (0);
}

void	ft_render_object(t_env *game)
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
				return (ft_putendl_fd("Error\nCannot render the game.", 2));
			x++;
		}
		y++;
	}
}
