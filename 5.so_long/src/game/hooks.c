/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:05:08 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/17 16:52:01 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_close(t_env *game)
{
	ft_free_tenv(game);
	exit(0);
}

int	ft_select_key(int keycode, t_env *game)
{
	if (keycode == 65307)
		ft_close(game);
	else if (keycode == 122 || keycode == 119 || keycode == 65362)
		ft_move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == 113 || keycode == 97 || keycode == 65361)
		ft_move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == 115 || keycode == 65364)
		ft_move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == 100 || keycode == 65363)
		ft_move_player(game, game->player_x + 1, game->player_y);
	return (0);
}

void	ft_hook(t_env *game)
{
	mlx_key_hook(game->win, ft_select_key, game);
	mlx_hook(game->win, 17, 0, ft_close, game);
}
