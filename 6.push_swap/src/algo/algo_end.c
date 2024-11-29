/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:26:33 by qupollet          #+#    #+#             */
/*   Updated: 2024/11/15 13:59:36 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_list	*ft_get_last(t_stack *stk);

void	ft_check_last_three(t_stack *stk_a, t_stack *stk_b)
{
	t_list	*last;

	last = ft_get_last(stk_a);
	if (*(int *)last->content > stk_b->max)
		ft_reverse_rotate(stk_a, "rra");
	last = ft_get_last(stk_a);
	if (*(int *)last->content > stk_b->max)
		ft_reverse_rotate(stk_a, "rra");
	last = ft_get_last(stk_a);
	if (*(int *)last->content > stk_b->max)
		ft_reverse_rotate(stk_a, "rra");
}

t_list	*ft_get_last(t_stack *stk)
{
	t_list		*cur;

	cur = stk->top;
	while (cur->next != stk->top)
		cur = cur->next;
	return (cur);
}

void	ft_check_rotate(t_stack *stk_a, t_stack *stk_b)
{
	t_list		*top_a;
	t_list		*last_a;
	t_list		*top_b;

	top_a = stk_a->top;
	last_a = ft_get_last(stk_a);
	top_b = stk_b->top;
	while (*(int *)top_a->content > *(int *)last_a->content
		&& *(int *)last_a->content > *(int *)top_b->content)
	{
		ft_reverse_rotate(stk_a, "rra");
		top_a = stk_a->top;
		last_a = ft_get_last(stk_a);
		top_b = stk_b->top;
	}
}

void	ft_final_insert(t_stack *stk_a, t_stack *stk_b)
{
	ft_update_min_max(stk_a);
	ft_update_min_max(stk_b);
	ft_check_last_three(stk_a, stk_b);
	while (stk_b->size > 0)
	{
		ft_check_rotate(stk_a, stk_b);
		ft_push(stk_b, stk_a, "pa");
	}
}
