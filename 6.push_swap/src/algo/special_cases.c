/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:22:52 by qupollet          #+#    #+#             */
/*   Updated: 2024/11/14 14:57:21 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_case2(t_stack *stk)
{
	int		nb1;
	int		nb2;

	nb1 = *(int *)stk->top->content;
	nb2 = *(int *)stk->top->next->content;
	if (nb1 > nb2)
		ft_swap(stk, "sa");
}

void	ft_sort_3(t_stack *stk, int nb1, int nb2, int nb3)
{
	if (nb1 > nb2 && nb1 > nb3)
	{
		if (nb2 > nb3)
		{
			ft_swap(stk, "sa");
			ft_reverse_rotate(stk, "rra");
		}
		else
			ft_rotate(stk, "ra");
	}
	else if (nb2 > nb1 && nb2 > nb3)
	{
		if (nb1 > nb3)
			ft_reverse_rotate(stk, "rra");
		else
		{
			ft_swap(stk, "sa");
			ft_rotate(stk, "ra");
		}
	}
	else
		ft_swap(stk, "sa");
}

void	ft_case3(t_stack *stk)
{
	int		nb1;
	int		nb2;
	int		nb3;

	if (ft_is_stack_sorted(stk) == 1)
		return ;
	nb1 = *(int *)stk->top->content;
	nb2 = *(int *)stk->top->next->content;
	nb3 = *(int *)stk->top->next->next->content;
	ft_sort_3(stk, nb1, nb2, nb3);
}

void	ft_case4(t_stack *stk_a, t_stack *stk_b)
{
	int		min;
	t_list	*cur;

	cur = stk_a->top;
	min = *(int *)cur->content;
	cur = cur->next;
	while (cur != stk_a->top)
	{
		if (min > *(int *)cur->content)
			min = *(int *)cur->content;
		cur = cur->next;
	}
	ft_put_a_to_top(stk_a, min);
	if (ft_is_stack_sorted(stk_a))
		return ;
	ft_push(stk_a, stk_b, "pb");
	ft_case3(stk_a);
	ft_push(stk_b, stk_a, "pa");
	stk_a->top->next->next->next->next = stk_a->top;
}

int	ft_check_special_cases(t_stack *stk_a, t_stack *stk_b)
{
	int		size;

	size = stk_a->size;
	if (size == 1)
		return (1);
	if (size == 2)
		return (ft_case2(stk_a), 1);
	if (size == 3)
		return (ft_case3(stk_a), 1);
	if (size == 4)
		return (ft_case4(stk_a, stk_b), 1);
	return (0);
}
