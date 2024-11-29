/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:30:51 by qupollet          #+#    #+#             */
/*   Updated: 2024/10/18 17:04:09 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_list		*current;
	t_list		*next;
	t_list		*first;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	first = stack->top;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		if (next == first)
			break ;
		current = next;
	}
	stack->size = 0;
	stack->top = NULL;
}

void	ft_free_chartab(char **tab)
{
	int		idx;

	if (!tab)
		return ;
	idx = 0;
	while (tab[idx])
	{
		free(tab[idx]);
		idx++;
	}
	free(tab);
}
