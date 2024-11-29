/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:30:57 by qupollet          #+#    #+#             */
/*   Updated: 2024/11/14 15:24:19 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_put_b_to_top(t_stack *stk, int nb)
{
	int		idx;

	idx = ft_find_elem(stk, nb);
	if (idx == -1)
		return ;
	if (idx <= stk->size / 2)
	{
		while (idx > 0)
		{
			ft_rotate(stk, "rb");
			idx--;
		}
	}
	else
	{
		while (idx < stk->size)
		{
			ft_reverse_rotate(stk, "rrb");
			idx++;
		}
	}
}

int	ft_algo_main(t_stack *stk_a, t_stack *stk_b)
{
	if (ft_is_stack_sorted(stk_a) == 1)
		return (0);
	if (ft_check_special_cases(stk_a, stk_b))
		return (0);
	ft_push(stk_a, stk_b, "pb");
	ft_push(stk_a, stk_b, "pb");
	if (*(int *)stk_b->top->content < *(int *)stk_b->top->next->content)
		ft_rotate(stk_b, "rb");
	ft_update_min_max(stk_b);
	while (stk_a->size != 3)
	{
		ft_put_in_b(stk_a, stk_b);
		ft_update_min_max(stk_b);
	}
	ft_case3(stk_a);
	ft_put_b_to_top(stk_b, stk_b->max);
	ft_final_insert(stk_a, stk_b);
	ft_update_min_max(stk_a);
	ft_put_a_to_top(stk_a, stk_a->min);
	return (0);
}
