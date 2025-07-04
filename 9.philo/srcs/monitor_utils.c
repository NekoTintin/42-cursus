/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:32:04 by qupollet          #+#    #+#             */
/*   Updated: 2025/07/04 14:00:50 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_finished_eating(t_philo *philo);
int	philo_is_dead(t_philo *philo);

int	philo_all_eaten(t_philo *philos)
{
	int			idx;

	idx = 0;
	while (idx < philos->data->nb)
	{
		if (philo_finished_eating(&philos[idx]) == 0)
			return (0);
		idx++;
	}
	stop_sim(philos->data);
	return (1);
}

int	philo_finished_eating(t_philo *philo)
{
	int			meals;

	if (philo->data->mxmeal <= 0)
		return (0);
	pthread_mutex_lock(&philo->meal_mtx);
	meals = philo->nb_meal;
	pthread_mutex_unlock(&philo->meal_mtx);
	if (meals >= philo->data->mxmeal && philo->data->mxmeal > 0)
		return (1);
	return (0);
}

int	philo_check_death(t_philo *philos)
{
	int		idx;
	int		nb;

	if (!philos)
		return (1);
	idx = 0;
	nb = philos->data->nb;
	while (idx < nb)
	{
		if (philo_is_dead(&philos[idx]) == 1)
			return (1);
		idx++;
	}
	return (0);
}

int	philo_is_dead(t_philo *philo)
{
	long long		curtime;
	long long		lmeal;

	pthread_mutex_lock(&philo->lmtx);
	lmeal = philo->lmeal;
	pthread_mutex_unlock(&philo->lmtx);
	curtime = get_time();
	if (curtime - lmeal > philo->data->tdie)
	{
		stop_sim(philo->data);
		curtime = get_time() - philo->data->start;
		pthread_mutex_lock(&philo->data->pmtx);
		printf("%lld %d died\n", curtime, philo->id + 1);
		pthread_mutex_unlock(&philo->data->pmtx);
		return (1);
	}
	return (0);
}
