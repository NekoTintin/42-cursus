/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:11:22 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/19 21:10:38 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_free_chartab(char **tab)
{
	int		idx;

	if (!tab)
		return ;
	idx = 0;
	while (tab[idx])
	{
		free(tab[idx]);
		idx++;
	}
	free(tab);
}

static void	ft_destroy_txt(t_env *game)
{
	if (game->txt->perso)
	{
		mlx_destroy_image(game->ptr, game->txt->perso);
		game->txt->perso = NULL;
	}
	if (game->txt->ground)
	{
		mlx_destroy_image(game->ptr, game->txt->ground);
		game->txt->ground = NULL;
	}
	if (game->txt->cookie)
	{
		mlx_destroy_image(game->ptr, game->txt->cookie);
		game->txt->cookie = NULL;
	}
	if (game->txt->exit)
	{
		mlx_destroy_image(game->ptr, game->txt->exit);
		game->txt->exit = NULL;
	}
	if (game->txt->wall)
		mlx_destroy_image(game->ptr, game->txt->wall);
	game->txt->wall = NULL;
	free(game->txt);
}

void	ft_free_tenv(t_env *game)
{
	if (!game)
		return ;
	if (game->win)
	{
		mlx_destroy_window(game->ptr, game->win);
		game->win = NULL;
	}
	if (game->map)
	{
		ft_free_chartab(game->map);
		game->map = NULL;
	}
	if (game->txt)
	{
		ft_destroy_txt(game);
		game->txt = NULL;
	}
	if (game->ptr)
	{
		mlx_destroy_display(game->ptr);
		free(game->ptr);
		game->ptr = NULL;
	}
	free(game);
}
