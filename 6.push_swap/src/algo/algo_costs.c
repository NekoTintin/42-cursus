/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:39:26 by qupollet          #+#    #+#             */
/*   Updated: 2024/11/12 15:37:37 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_cost_to_top(t_stack *stk, int nb)
{
	t_list		*cur;
	int			res;

	cur = stk->top;
	res = 0;
	while (1)
	{
		if (*(int *)cur->content == nb)
			return (res);
		cur = cur->next;
		res++;
		if (cur == stk->top)
			break ;
	}
	return (-1);
}

//  Search the nearest value 
int	ft_get_near(t_stack *stk, int nb)
{
	t_list		*cur;
	int			nbr_most_near;
	int			result;
	int			first_pass;
	int			tmp_result;

	cur = stk->top;
	while (*(int *)cur->content >= nb)
		cur = cur->next;
	nbr_most_near = *(int *)cur->content;
	result = nb - nbr_most_near;
	first_pass = 1;
	while (cur != stk->top || first_pass)
	{
		first_pass = 0;
		tmp_result = nb - *(int *)cur->content;
		if (tmp_result < result && tmp_result > 0)
		{
			result = tmp_result;
			nbr_most_near = *(int *)cur->content;
		}
		cur = cur->next;
	}
	return (nbr_most_near);
}

//  Set a target value for all number in stk_a, target contain the nearest value
void	ft_get_target_and_cost(t_stack *stk_a, t_stack *stk_b)
{
	t_list	*cur;

	cur = stk_a->top;
	while (1)
	{
		if (*(int *)cur->content < stk_b->min)
			cur->target = stk_b->max;
		else
			cur->target = ft_get_near(stk_b, *(int *)cur->content);
		cur = cur->next;
		if (cur == stk_a->top)
			break ;
	}
	cur = stk_a->top;
	while (1)
	{
		cur->cost_a = ft_cost_to_top(stk_a, *(int *)cur->content);
		cur->cost_b = ft_cost_to_top(stk_b, cur->target);
		cur = cur->next;
		if (cur == stk_a->top)
			break ;
	}
}

int	ft_select_minimum_cost(t_stack *stk_a)
{
	t_list	*cur;
	int		min_pos;
	int		min_cost;

	min_pos = 0;
	min_cost = INT_MAX;
	cur = stk_a->top;
	while (1)
	{
		if ((cur->cost_a + cur->cost_b + 1) < min_cost)
		{
			min_pos = *(int *)cur->content;
			min_cost = cur->cost_a + cur->cost_b;
		}
		cur = cur->next;
		if (cur == stk_a->top)
			break ;
	}
	return (min_pos);
}
