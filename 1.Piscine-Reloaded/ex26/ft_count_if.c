/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:32:45 by qupollet          #+#    #+#             */
/*   Updated: 2024/05/16 11:55:21 by qupollet         ###   ########.fr       */
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
