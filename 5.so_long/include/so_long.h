/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:39:34 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/20 16:22:20 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef TILE_SIZE
#  define TILE_SIZE 96
# endif

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_textures
{
	void		*perso;
	void		*ground;
	void		*exit;
	void		*cookie;
	void		*wall;
}				t_textures;

typedef struct s_env
{
	void		*ptr;
	void		*win;
	t_textures	*txt;
	char		**map;
	int			collec;
	int			nb_mov;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
}				t_env;

int		ft_init_game(t_env *game, char *map);
void	ft_get_window_size(t_env *game, int *width, int *height);
void	ft_render_map(t_env *game);
int		ft_load_textures(t_env *game);
void	ft_render_object(t_env *game);
int		ft_can_be_finished(char **tiles);

char	**ft_map(char *filename);
char	**ft_load_tiles(char *filepath);
int		ft_map_is_ber(char *filepath);
int		ft_verify_content(char **tiles);
int		ft_can_be_finished(char **tiles);

void	ft_hook(t_env *game);
int		ft_close(t_env *game);
int		ft_move_player(t_env *game, int new_x, int new_y);

void	ft_free_chartab(char **tab);
void	ft_free_tenv(t_env *game);
void	ft_get_player_pos(char **map, int *x, int *y);
void	ft_get_exit_pos(t_env *game, int *x, int *y);
int		ft_get_nb_collec(char **map);
void	ft_get_map_size(char **map, int *x, int *y);
char	**ft_tabdup(char **str);
int		ft_is_exit_v(char **map);

#endif