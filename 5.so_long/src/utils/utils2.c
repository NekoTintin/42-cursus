/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:21:32 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/24 17:06:57 by NekoTintin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_is_exit_v(char **map)
{
	int	idx;
	int	idy;

	idy = 0;
	while (map[idy] != NULL)
	{
		idx = 0;
		while (map[idy][idx] != '\0')
		{
			if (map[idy][idx] == 'E')
				return (0);
			idx++;
		}
		idy++;
	}
	return (1);
}
