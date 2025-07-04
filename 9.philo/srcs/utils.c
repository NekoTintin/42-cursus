/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 02:20:45 by qupollet          #+#    #+#             */
/*   Updated: 2025/07/04 13:53:51 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	test;

	test = nmemb * size;
	if (nmemb != 0 && test / nmemb != size)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	memset(ptr, 0, (nmemb * size));
	return (ptr);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	idx;
	int				sign;
	int				total;

	idx = 0;
	sign = 1;
	total = 0;
	while ((nptr[idx] >= 9 && nptr[idx] <= 13) || nptr[idx] == ' ')
		idx++;
	if (nptr[idx] == '-' || nptr[idx] == '+')
	{
		if (nptr[idx] == '-')
			sign *= -1;
		idx++;
	}
	while (nptr[idx] >= '0' && nptr[idx] <= '9')
	{
		total = total * 10 + (nptr[idx] - 48);
		idx++;
	}
	return (total * sign);
}

void	stop_sim(t_data *data)
{
	pthread_mutex_lock(&data->run_mtx);
	data->run = 0;
	pthread_mutex_unlock(&data->run_mtx);
}
