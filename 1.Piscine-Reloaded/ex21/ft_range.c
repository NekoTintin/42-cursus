/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:15:16 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/24 16:52:52 by NekoTintin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	range_size;
	int	cur;

	range_size = max - min;
	if (range_size <= 0)
		return (NULL);
	tab = malloc(sizeof(int) * range_size);
	if (tab == NULL)
		return (NULL);
	cur = 0;
	while (cur < range_size)
	{
		tab[cur] = min + cur;
		cur++;
	}
	return (tab);
}
