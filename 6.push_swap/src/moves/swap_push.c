/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:28:00 by qupollet          #+#    #+#             */
/*   Updated: 2024/10/21 16:39:41 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_swap(t_stack *stk, char *move)
{
	t_list	*n1;
	t_list	*n2;
	t_list	*current;

	if (stk == NULL || stk->size < 2)
		return ;
	n1 = stk->top;
	n2 = n1->next;
	n1->next = n2->next;
	n2->next = n1;
	current = stk->top;
	while (current->next != stk->top)
		current = current->next;
	current->next = n2;
	stk->top = n2;
	if (ft_strncmp(move, "ss", ft_strlen(move)) != 0)
		ft_print_move(move);
}

void	ft_push(t_stack *stk_src, t_stack *stk_dst, char *move)
{
	t_list		*n;
	t_list		*cur;

	if (stk_src->size < 1)
		return ;
	n = stk_src->top;
	if (stk_src->size == 1)
		stk_src->top = NULL;
	else
	{
		cur = stk_src->top;
		while (cur->next != stk_src->top)
			cur = cur->next;
		stk_src->top = n->next;
		cur->next = stk_src->top;
	}
	stk_src->size--;
	stk_dst->size++;
	ft_addfront_circular(&stk_dst->top, n);
	ft_print_move(move);
}

void	ft_swap_s(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a, "ss");
	ft_swap(stack_b, "ss");
	ft_print_move("ss");
}
