/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:36:13 by qupollet          #+#    #+#             */
/*   Updated: 2024/11/14 14:57:21 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_find_elem(t_stack *stk, int nb)
{
	t_list		*tmp;
	int			idx;

	if (!stk || !stk->top)
		return (-2);
	tmp = stk->top;
	if (nb == *(int *)tmp->content)
		return (0);
	tmp = tmp->next;
	idx = 1;
	while (tmp != stk->top)
	{
		if (nb == *(int *)tmp->content)
			return (idx);
		tmp = tmp->next;
		idx++;
	}
	return (-1);
}

void	ft_put_a_to_top(t_stack *stk, int nb)
{
	int		idx;

	idx = ft_find_elem(stk, nb);
	if (idx == -1)
		return ;
	if (idx <= stk->size / 2)
	{
		while (idx > 0)
		{
			ft_rotate(stk, "ra");
			idx--;
		}
	}
	else
	{
		while (idx < stk->size)
		{
			ft_reverse_rotate(stk, "rra");
			idx++;
		}
	}
}

void	ft_addfront_circular(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst && new)
	{
		if (*lst == NULL)
		{
			*lst = new;
			new->next = new;
		}
		else
		{
			last = *lst;
			while (last->next != *lst)
				last = last->next;
			new->next = *lst;
			*lst = new;
			last->next = *lst;
		}
	}
}

void	ft_update_min_max(t_stack *stk)
{
	int		min;
	int		max;
	t_list	*tmp;

	tmp = stk->top;
	min = *(int *)tmp->content;
	max = *(int *)tmp->content;
	tmp = tmp->next;
	while (tmp != stk->top)
	{
		if (*(int *)tmp->content > max)
			max = *(int *)tmp->content;
		if (*(int *)tmp->content < min)
			min = *(int *)tmp->content;
		tmp = tmp->next;
	}
	stk->min = min;
	stk->max = max;
}
