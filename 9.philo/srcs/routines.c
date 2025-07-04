/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:09:45 by qupollet          #+#    #+#             */
/*   Updated: 2025/07/04 14:14:38 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Create a delay to avoid taking the same fork at the beginning
// In order: EAT, SLEEP, THINK
void	*philo_rt(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		custom_usleep(philo, (philo->data->teat / 2));
	while (is_simrun(philo->data) == 1)
	{
		if (ft_eating(philo) != 0)
			break ;
		if (ft_dreaming(philo) != 0)
			break ;
		if (ft_thinking_about_life(philo) != 0)
			break ;
	}
	return (NULL);
}

void	*ft_moni_rt(void *arg)
{
	t_philo		*philos;
	t_data		*data;

	philos = (t_philo *)arg;
	data = philos->data;
	while (is_simrun(data) == 1)
	{
		if (philo_check_death(philos) == 1)
			return (NULL);
		if (philo_all_eaten(philos) == 1)
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
