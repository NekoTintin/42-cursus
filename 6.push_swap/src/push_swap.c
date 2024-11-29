/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:20:34 by qupollet          #+#    #+#             */
/*   Updated: 2024/11/13 16:43:43 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	int			res;

	if (argc == 1)
		return (1);
	stack_a = ft_init_stack();
	stack_b = ft_init_stack();
	if (stack_a.size == -1 || stack_b.size == -1)
		return (1);
	if (ft_check_arg(&stack_a, argc, argv) == 1)
		return (ft_free_stack(&stack_a), 1);
	res = ft_algo_main(&stack_a, &stack_b);
	if (ft_is_stack_sorted(&stack_a) == 0)
		ft_putendl_fd("Error", 2);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (res);
}
