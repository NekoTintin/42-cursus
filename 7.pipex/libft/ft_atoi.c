/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <quentinpollet27@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:10 by qupollet          #+#    #+#             */
/*   Updated: 2024/05/31 15:39:14 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	unsigned int	index;
	int				sign;
	int				total;

	index = 0;
	sign = 1;
	total = 0;
	while ((nptr[index] >= 9 && nptr[index] <= 13) || nptr[index] == ' ')
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			sign *= -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		total = total * 10 + (nptr[index] - 48);
		index++;
	}
	return (total * sign);
}
