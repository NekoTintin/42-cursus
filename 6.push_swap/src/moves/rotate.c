/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:43:23 by qupollet          #+#    #+#             */
/*   Updated: 2024/11/13 17:19:18 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// Update for circular lists

void	ft_rotate_a_b(t_stack *stk_a, t_stack *stk_b)
{
	ft_rotate(stk_a, "rr");
	ft_rotate(stk_b, "rr");
	ft_print_move("rr");
}

void	ft_reverse_rotate_a_b(t_stack *stk_a, t_stack *stk_b)
{
	ft_reverse_rotate(stk_a, "rrr");
	ft_reverse_rotate(stk_b, "rrr");
	ft_print_move("rrr");
}

void	ft_rotate(t_stack *stk, char *move)
{
	if (stk == NULL || stk->size < 2)
		return ;
	stk->top = stk->top->next;
	if (ft_strncmp(move, "rr", ft_strlen(move)) != 0)
		ft_print_move(move);
}

void	ft_reverse_rotate(t_stack *stk, char *move)
{
	t_list		*current;

	if (stk == NULL || stk->size < 2)
		return ;
	current = stk->top;
	while (current->next != stk->top)
		current = current->next;
	stk->top = current;
	if (ft_strncmp(move, "rrr", ft_strlen(move)) != 0)
		ft_print_move(move);
}
