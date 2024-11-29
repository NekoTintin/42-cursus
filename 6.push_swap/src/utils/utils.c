/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:57:38 by qupollet          #+#    #+#             */
/*   Updated: 2024/10/21 16:08:20 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_is_stack_sorted(t_stack *stk)
{
	int		new_min;
	t_list	*current;

	if (!stk || !stk->top)
		return (1);
	new_min = *(int *)stk->top->content;
	current = stk->top->next;
	while (current != stk->top)
	{
		if (*(int *)current->content < new_min)
			return (0);
		new_min = *(int *)current->content;
		current = current->next;
	}
	return (1);
}

long long	ft_not_a_atoll(const char *nptr)
{
	long long		total;
	int				sign;

	sign = 1;
	total = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (total > (LLONG_MAX - (*nptr - '0')) / 10)
			return (LLONG_MIN);
		total = total * 10 + (*nptr - 48);
		nptr++;
	}
	if (ft_isalpha(*nptr))
		return (LLONG_MIN);
	return (total * (long long)sign);
}

void	ft_print_move(char *move)
{
	ft_printf("%s\n", move);
}

int	ft_make_circular(t_stack *stk)
{
	t_list		*current;

	if (!stk || !stk->top)
		return (1);
	current = stk->top;
	while (current->next)
		current = current->next;
	current->next = stk->top;
	return (0);
}

int	ft_contain_char(char *str)
{
	int		idx;

	idx = 0;
	if (str[idx] == '+' || str[idx] == '-')
		idx++;
	while (str[idx] != '\0')
	{
		if (!ft_isdigit(str[idx]))
			return (1);
		idx++;
	}
	return (0);
}
