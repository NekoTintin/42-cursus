/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:01:07 by qupollet          #+#    #+#             */
/*   Updated: 2024/11/13 18:05:59 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>

int	ft_check_overflow(char **argv);
int	ft_check_duplicates(t_stack *stk);

t_stack	ft_init_stack(void)
{
	t_stack		stack;

	stack.top = NULL;
	stack.size = 0;
	stack.min = 0;
	stack.max = 0;
	return (stack);
}

int	ft_fill_a(t_stack *stk_a, char **arg)
{
	int			idx;
	int			*value;
	t_list		*tmp;

	idx = 0;
	while (arg[idx])
	{
		if (ft_contain_char(arg[idx]))
			return (1);
		value = ft_calloc(1, sizeof(int));
		if (!value)
			return (1);
		*value = (int)ft_not_a_atoll(arg[idx]);
		tmp = ft_lstnew(value);
		if (!tmp)
			return (free(value), 1);
		ft_lstadd_back(&stk_a->top, tmp);
		stk_a->size++;
		idx++;
	}
	return (0);
}

int	ft_check_arg(t_stack *stk_a, int argc, char **argv)
{
	int		idx;
	char	**tmp;

	if (ft_check_overflow(argv) == 1)
		return (ft_putstr_fd("Error\n", 2), 1);
	idx = 1;
	while (idx < argc)
	{
		tmp = ft_split(argv[idx], ' ');
		if (!tmp)
			return (ft_putstr_fd("Error\n", 2), 1);
		if (ft_fill_a(stk_a, tmp) == 1)
		{
			ft_free_chartab(tmp);
			return (ft_putstr_fd("Error\n", 2), 1);
		}
		ft_free_chartab(tmp);
		idx++;
	}
	if (ft_check_duplicates(stk_a) == 1)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (ft_make_circular(stk_a) == 1)
		return (ft_putstr_fd("Error\n", 2), 1);
	return (0);
}

int	ft_check_overflow(char **argv)
{
	int			idx;
	int			split_idx;
	char		**sp;
	long long	tmp;

	idx = 1;
	while (argv[idx] != NULL)
	{
		sp = ft_split(argv[idx], ' ');
		if (!sp)
			return (1);
		split_idx = 0;
		while (sp[split_idx] != NULL)
		{
			tmp = ft_not_a_atoll(sp[split_idx]);
			if (tmp == LLONG_MIN || tmp > INT_MAX || tmp < INT_MIN)
				return (ft_free_chartab(sp), 1);
			split_idx++;
		}
		ft_free_chartab(sp);
		idx++;
	}
	return (0);
}

int	ft_check_duplicates(t_stack *stk)
{
	t_list	*cur;
	t_list	*next;
	int		cur_val;
	int		next_val;

	cur = stk->top;
	while (cur)
	{
		cur_val = *(int *)cur->content;
		next = cur->next;
		while (next)
		{
			next_val = *(int *)next->content;
			if (cur_val == next_val)
				return (1);
			next = next->next;
		}
		cur = cur->next;
	}
	return (0);
}
