/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:02:27 by qupollet          #+#    #+#             */
/*   Updated: 2025/07/04 00:34:34 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000LL) + (time.tv_usec / 1000));
}

int	is_simrun(t_data *data)
{
	int		val;

	val = 0;
	pthread_mutex_lock(&data->run_mtx);
	val = data->run;
	pthread_mutex_unlock(&data->run_mtx);
	return (val);
}

void	print_act(t_philo *philo, const char *str)
{
	long long	cur_time;

	pthread_mutex_lock(&philo->data->pmtx);
	if (is_simrun(philo->data) == 1)
	{
		cur_time = (get_time() - philo->data->start);
		printf("%lld %d %s\n", cur_time, philo->id + 1, str);
		pthread_mutex_unlock(&philo->data->pmtx);
		return ;
	}
	pthread_mutex_unlock(&philo->data->pmtx);
}

int	custom_usleep(t_philo *philo, long long time)
{
	long long	stime;

	stime = get_time();
	while (get_time() - stime < time)
	{
		if (is_simrun(philo->data) == 0)
			return (1);
		usleep(100);
	}
	return (0);
}

int	ft_case_one(int tdie)
{
	printf("0 1 is thinking\n");
	printf("0 1 has taken a fork\n");
	usleep(tdie * 1000);
	printf("%d 1 died\n", tdie);
	return (0);
}
