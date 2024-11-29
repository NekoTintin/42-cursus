/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:34:54 by qupollet          #+#    #+#             */
/*   Updated: 2024/11/12 16:01:18 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_move_stk_a(t_stack *stk_a, int nb_moves)
{
	if (nb_moves <= stk_a->size / 2)
		while (nb_moves-- > 0)
			ft_rotate(stk_a, "ra");
	else
		while (nb_moves++ < stk_a->size)
			ft_reverse_rotate(stk_a, "rra");
}

void	ft_move_stk_b(t_stack *stk_b, int nb_moves)
{
	if (nb_moves <= stk_b->size / 2)
		while (nb_moves-- > 0)
			ft_rotate(stk_b, "rb");
	else
		while (nb_moves++ < stk_b->size)
			ft_reverse_rotate(stk_b, "rrb");
}

void	ft_double_rota(t_stack *stk_a, t_stack *stk_b, t_list *cur)
{
	if (cur->cost_a <= (stk_a->size / 2) && cur->cost_b <= (stk_b->size / 2))
	{
		while (cur->cost_a > 0 && cur->cost_b > 0)
		{
			ft_rotate_a_b(stk_a, stk_b);
			cur->cost_a--;
			cur->cost_b--;
		}
	}
	else if (cur->cost_a > (stk_a->size / 2) && cur->cost_b > (stk_b->size / 2))
	{
		while (cur->cost_a < stk_a->size && cur->cost_b < stk_b->size)
		{
			ft_reverse_rotate_a_b(stk_a, stk_b);
			cur->cost_a++;
			cur->cost_b++;
		}
	}
	ft_move_stk_a(stk_a, cur->cost_a);
	ft_move_stk_b(stk_b, cur->cost_b);
}

void	ft_ascend_in_a_b(t_stack *stk_a, t_stack *stk_b, int nb)
{
	t_list	*cur;

	cur = stk_a->top;
	while (1)
	{
		if (*(int *)cur->content == nb)
			break ;
		cur = cur->next;
		if (cur == stk_a->top)
			break ;
	}
	ft_double_rota(stk_a, stk_b, cur);
}
