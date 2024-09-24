/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:38:11 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/19 20:32:25 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	main(int argc, char **argv)
{
	t_env		*game;

	if (argc != 2)
		return (ft_putendl_fd("Error\nso_long takes one argument.", 2), 1);
	game = ft_calloc(1, sizeof(t_env));
	if (!game)
		return (1);
	if (ft_init_game(game, argv[1]) == 1)
		return (ft_free_tenv(game), 1);
	game->txt = ft_calloc(1, sizeof(t_textures));
	if (!game->txt)
		return (1);
	if (ft_load_textures(game) == -1)
		return (1);
	ft_render_map(game);
	ft_render_object(game);
	ft_hook(game);
	mlx_loop(game->ptr);
	return (0);
}
