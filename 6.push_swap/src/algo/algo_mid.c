/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:44:15 by qupollet          #+#    #+#             */
/*   Updated: 2024/11/12 14:10:58 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

int	ft_put_in_b(t_stack *stk_a, t_stack *stk_b)
{
	int		to_ascend;

	ft_get_target_and_cost(stk_a, stk_b);
	to_ascend = ft_select_minimum_cost(stk_a);
	ft_ascend_in_a_b(stk_a, stk_b, to_ascend);
	ft_push(stk_a, stk_b, "pb");
	return (0);
}
