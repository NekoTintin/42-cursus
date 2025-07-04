/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 02:09:14 by qupollet          #+#    #+#             */
/*   Updated: 2025/07/04 17:14:49 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	create_philo(t_philo *philo, t_data *data, t_fork *forks)
{
	int			idx;

	idx = 0;
	while (idx < data->nb)
	{
		philo[idx].id = idx;
		philo[idx].data = data;
		philo[idx].nb_meal = 0;
		if (idx % 2 == 0)
		{
			philo[idx].lfork = &forks[idx];
			philo[idx].rfork = &forks[(idx + 1) % data->nb];
		}
		else
		{
			philo[idx].rfork = &forks[idx];
			philo[idx].lfork = &forks[(idx + 1) % data->nb];
		}
		pthread_mutex_init(&philo[idx].lmtx, NULL);
		pthread_mutex_init(&philo[idx].meal_mtx, NULL);
		idx++;
	}
	return (0);
}

int	create_forks(int nb, t_fork *forks)
{
	int		idx;

	idx = 0;
	while (idx < nb)
	{
		pthread_mutex_init(&forks[idx].fmtx, NULL);
		forks[idx].id = idx;
		idx++;
	}
	return (0);
}

int	create_data(int argc, char **argv, t_data *data)
{
	data->nb = ft_atoi(argv[1]);
	data->tdie = ft_atoi(argv[2]);
	data->teat = ft_atoi(argv[3]);
	data->tsleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->mxmeal = ft_atoi(argv[5]);
	else
		data->mxmeal = 0;
	data->run = 1;
	pthread_mutex_init(&data->pmtx, NULL);
	pthread_mutex_init(&data->run_mtx, NULL);
	return (0);
}

int	create_threads(t_philo *philos)
{
	int		idx;

	idx = 0;
	philos->data->start = get_time();
	while (idx < philos->data->nb)
	{
		philos[idx].lmeal = philos->data->start;
		if (pthread_create(&philos[idx].td, NULL, philo_rt,
				&philos[idx]) != 0)
			return (1);
		idx++;
	}
	return (0);
}
