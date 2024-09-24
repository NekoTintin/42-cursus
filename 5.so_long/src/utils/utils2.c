/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:21:32 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/20 16:25:04 by qupollet         ###   ########.fr       */
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