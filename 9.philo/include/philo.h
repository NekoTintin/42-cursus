/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:18:38 by qupollet          #+#    #+#             */
/*   Updated: 2025/07/04 13:59:14 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// Custom messages
# define ARG_ERR "Philo need 4 or 5 arguments to run.\n"
# define INT_ERR "Philo need only int arguments (int must be positive).\n"
# define STRUCT_ERR "Failed to create structures.\n"

# define MIN_PHI 1
# define MAX_PHI 200
# define MIN_INT -2147483648
# define MAX_INT 2147483647

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_fork	t_fork;

// Prog Struct
typedef struct s_data
{
	int					nb;
	int					tdie;
	int					teat;
	int					tsleep;
	int					mxmeal;
	int					run;
	long long			start;
	int					forks_init;
	pthread_mutex_t		pmtx;
	pthread_mutex_t		run_mtx;
	pthread_t			moni;
}						t_data;

// Philo Struct
typedef struct s_philo
{
	int					id;
	pthread_t			td;
	long long			lmeal;
	pthread_mutex_t		lmtx;
	int					nb_meal;
	pthread_mutex_t		meal_mtx;
	t_fork				*lfork;
	t_fork				*rfork;
	t_data				*data;
}						t_philo;

// Forks Struct
typedef struct s_fork
{
	int				id;
	pthread_mutex_t	fmtx;
}				t_fork;

// acts.c
int			ft_eating(t_philo *philo);
int			ft_dreaming(t_philo *philo);
int			ft_thinking_about_life(t_philo *philo);

// check_args.c
int			check_philo_nb(char *nb);
int			ft_check_arg(char **argv);

// init.c
int			create_philo(t_philo *philo, t_data *data, t_fork *forks);
int			create_forks(int nb, t_fork *forks);
int			create_data(int argc, char **argv, t_data *data);
int			create_threads(t_philo *philos);

// destroy.c
int			destroy_all_forks(t_fork *forks, int nb);
int			destroy_data(t_data *data);
int			destroy_philos(t_philo *philos, int nb);
int			join_threads(t_philo *philos, t_data *data, t_fork *forks);

// monitor_utils.c
int			philo_all_eaten(t_philo *philos);
int			philo_check_death(t_philo *philos);

// project_utils.c
long long	get_time(void);
int			is_simrun(t_data *data);
void		print_act(t_philo *philo, const char *str);
int			custom_usleep(t_philo *philo, long long time);
int			ft_case_one(int tdie);

// routines.c
void		*philo_rt(void *arg);
void		*ft_moni_rt(void *arg);

// utils.c
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_atoi(const char *nptr);
void		stop_sim(t_data *data);

#endif