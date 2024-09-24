/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:58:01 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/24 17:06:37 by NekoTintin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_init_game(t_env *game, char *map)
{
	int		width;
	int		height;

	width = 0;
	height = 0;
	game->map = ft_map(map);
	if (!game->map)
		return (1);
	game->ptr = mlx_init();
	if (!game->ptr)
		ft_free_tenv(game);
	ft_get_window_size(game, &width, &height);
	game->win = mlx_new_window(game->ptr, width, height, "so_long");
	if (!game->win)
		ft_free_tenv(game);
	ft_get_exit_pos(game, &game->exit_x, &game->exit_y);
	game->collec = ft_get_nb_collec(game->map);
	ft_get_player_pos(game->map, &game->player_x, &game->player_y);
	game->nb_mov = 0;
	return (0);
}

void	ft_get_window_size(t_env *game, int *width, int *height)
{
	int		w_map;
	int		h_map;
	int		idx;

	w_map = ft_strlen(game->map[0]);
	h_map = 0;
	idx = -1;
	while (game->map[++idx] != NULL)
		h_map++;
	*width = w_map * TILE_SIZE;
	*height = h_map * TILE_SIZE;
}

int	ft_load_textures(t_env *game)
{
	int		t;

	t = TILE_SIZE;
	game->txt->perso = mlx_xpm_file_to_image(game->ptr, "sprites/char.xpm",
			&t, &t);
	if (!game->txt->perso)
		return (ft_free_tenv(game), -1);
	game->txt->cookie = mlx_xpm_file_to_image(game->ptr, "sprites/cookie.xpm",
			&t, &t);
	if (!game->txt->cookie)
		return (ft_free_tenv(game), -1);
	game->txt->wall = mlx_xpm_file_to_image(game->ptr, "sprites/wall.xpm",
			&t, &t);
	if (!game->txt->wall)
		return (ft_free_tenv(game), -1);
	game->txt->exit = mlx_xpm_file_to_image(game->ptr, "sprites/exit.xpm",
			&t, &t);
	if (!game->txt->exit)
		return (ft_free_tenv(game), -1);
	game->txt->ground = mlx_xpm_file_to_image(game->ptr, "sprites/ground.xpm",
			&t, &t);
	if (!game->txt->ground)
		return (ft_free_tenv(game), -1);
	return (0);
}
