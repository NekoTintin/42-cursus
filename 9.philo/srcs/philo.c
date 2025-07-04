/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 02:08:07 by qupollet          #+#    #+#             */
/*   Updated: 2025/07/04 17:06:18 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_philo		philos[MAX_PHI];
	t_fork		forks[MAX_PHI];

	if (argc < 5 || argc > 6)
		return (printf("%s", ARG_ERR), 1);
	if (ft_check_arg(argv) != 0)
		return (1);
	if (check_philo_nb(argv[1]) != 0)
		return (1);
	create_data(argc, argv, &data);
	create_forks(data.nb, forks);
	create_philo(philos, &data, forks);
	if (data.nb == 1)
		return (ft_case_one(data.tdie), 0);
	data.start = get_time();
	if (create_philo(philos, &data, forks) != 0)
		return (1);
	if (create_threads(philos) != 0)
		return (1);
	if (pthread_create(&data.moni, NULL, ft_moni_rt, philos) != 0)
		return (1);
	if (join_threads(philos, &data, forks) != 0)
		return (1);
	return (0);
}
