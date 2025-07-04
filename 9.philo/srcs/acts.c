/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:05:25 by qupollet          #+#    #+#             */
/*   Updated: 2025/07/04 15:30:25 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	eating_lock(t_philo *philo)
{
	pthread_mutex_t			*first;
	pthread_mutex_t			*second;

	if (philo->lfork < philo->rfork)
	{
		first = &philo->lfork->fmtx;
		second = &philo->rfork->fmtx;
	}
	else
	{
		first = &philo->rfork->fmtx;
		second = &philo->lfork->fmtx;
	}
	pthread_mutex_lock(first);
	print_act(philo, "has taken a fork");
	pthread_mutex_lock(second);
	print_act(philo, "has taken a fork");
	return (0);
}

void	eating_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->lfork->fmtx);
	pthread_mutex_unlock(&philo->rfork->fmtx);
}

int	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mtx);
	if (philo->data->mxmeal > 0 && philo->nb_meal >= philo->data->mxmeal)
	{
		pthread_mutex_unlock(&philo->meal_mtx);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_mtx);
	eating_lock(philo);
	pthread_mutex_lock(&philo->lmtx);
	philo->lmeal = get_time();
	pthread_mutex_unlock(&philo->lmtx);
	print_act(philo, "is eating");
	pthread_mutex_lock(&philo->meal_mtx);
	philo->nb_meal++;
	pthread_mutex_unlock(&philo->meal_mtx);
	custom_usleep(philo, philo->data->teat);
	eating_unlock(philo);
	return (0);
}

int	ft_dreaming(t_philo *philo)
{
	int			usleep_result;

	usleep_result = 0;
	print_act(philo, "is sleeping");
	usleep_result = custom_usleep(philo, philo->data->tsleep);
	return (usleep_result);
}

// Why (data->tdie - (data->teat + data->tsleep)) * 0.8 ?
// data->teat - data->tsleep is the time left for thinking
// * 0.8 is just a security margin
int	ft_thinking_about_life(t_philo *philo)
{
	int			tthink;
	t_data		*data;

	data = philo->data;
	print_act(philo, "is thinking");
	tthink = 0;
	if (philo->data->nb % 2 != 0)
	{
		tthink = (data->tdie - (data->teat + data->tsleep)) * 0.8;
	}
	custom_usleep(philo, tthink);
	return (0);
}
