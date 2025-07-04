/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:39:50 by qupollet          #+#    #+#             */
/*   Updated: 2025/07/04 13:47:45 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	destroy_all_forks(t_fork *forks, int nb)
{
	int		idx;

	idx = 0;
	while (idx < nb)
	{
		if (pthread_mutex_destroy(&forks[idx].fmtx) != 0)
			return (1);
		idx++;
	}
	return (0);
}

int	destroy_data(t_data *data)
{
	if (pthread_mutex_destroy(&data->pmtx) != 0)
		return (1);
	if (pthread_mutex_destroy(&data->run_mtx) != 0)
		return (1);
	return (0);
}

int	destroy_all_philos(t_philo *philos, int nb)
{
	int		idx;

	idx = 0;
	while (idx < nb)
	{
		if (pthread_mutex_destroy(&philos[idx].lmtx) != 0)
			return (1);
		if (pthread_mutex_destroy(&philos[idx].meal_mtx) != 0)
			return (1);
		idx++;
	}
	return (0);
}

int	join_threads(t_philo *philos, t_data *data, t_fork *forks)
{
	int		idx;

	idx = 0;
	while (idx < data->nb)
	{
		if (pthread_join(philos[idx].td, NULL) != 0)
			return (1);
		idx++;
	}
	if (pthread_join(data->moni, NULL) != 0)
		return (1);
	if (destroy_all_forks(forks, data->nb) != 0)
		return (1);
	if (destroy_data(data) != 0)
		return (1);
	if (destroy_all_philos(philos, data->nb) != 0)
		return (1);
	return (0);
}
