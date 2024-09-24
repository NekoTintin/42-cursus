/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:32:45 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/24 16:53:25 by NekoTintin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	nb;
	int	index;

	nb = 0;
	index = 0;
	while (tab[index] != 0)
	{
		if (f(tab[index]) == 1)
			nb++;
		index++;
	}
	return (nb);
}
