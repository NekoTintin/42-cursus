/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:37:55 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/19 12:27:55 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_pos_valid(t_env *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	return (1);
}

int	ft_move_player(t_env *game, int new_x, int new_y)
{
	if (ft_pos_valid(game, new_x, new_y) == 0)
		return (1);
	game->nb_mov++;
	if (new_x == game->exit_x && new_y == game->exit_y
		&& game->collec == 0)
	{
		ft_putendl_fd("Congratulations, you win the game!", 1);
		ft_close(game);
	}
	if (game->map[new_y][new_x] == 'C')
	{
		game->map[new_y][new_x] = '0';
		game->collec--;
	}
	mlx_put_image_to_window(game->ptr, game->win, game->txt->ground,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
	game->player_x = new_x;
	game->player_y = new_y;
	ft_render_object(game);
	ft_printf("Moves: %d\n", game->nb_mov);
	return (0);
}
