/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:55:17 by qupollet          #+#    #+#             */
/*   Updated: 2025/07/04 17:09:01 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi_safe(const char *nptr, int *out);

int	check_philo_nb(char *nb)
{
	int		res;

	res = ft_atoi(nb);
	if (res > MAX_PHI || res < MIN_PHI)
	{
		printf("Philo need a number of philosophers between 1 and 200.\n");
		return (1);
	}
	return (0);
}

int	ft_check_arg(char **argv)
{
	int		i;
	int		res;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi_safe(argv[i], &res) == 0)
		{
			printf("Invalid argument: %s\n", argv[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi_safe(const char *nptr, int *out)
{
	unsigned int	idx;
	int				sign;
	long long		total;

	idx = 0;
	sign = 1;
	total = 0;
	while ((nptr[idx] >= 9 && nptr[idx] <= 13) || nptr[idx] == ' ')
		idx++;
	if (nptr[idx] == '-' || nptr[idx] == '+')
		return (0);
	while (nptr[idx] >= '0' && nptr[idx] <= '9')
	{
		total = total * 10 + (nptr[idx] - 48);
		if ((sign == 1 && total > MAX_INT)
			|| (sign == -1 && total < MIN_INT))
			return (0);
		idx++;
	}
	if (nptr[idx] != '\0')
		return (0);
	*out = (int)(total * sign);
	return (1);
}
