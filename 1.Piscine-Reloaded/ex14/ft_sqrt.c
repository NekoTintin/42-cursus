/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:23:54 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/24 16:52:09 by NekoTintin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	total;

	i = 1;
	total = 0;
	if (nb <= 0)
		return (0);
	while (nb > 0)
	{
		nb -= i;
		i += 2;
		total++;
	}
	if (nb < 0)
		return (0);
	return (total);
}
