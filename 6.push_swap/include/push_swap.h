/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:16:05 by qupollet          #+#    #+#             */
/*   Updated: 2024/11/14 14:57:21 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	t_list		*top;
	int			size;
	int			min;
	int			max;
}				t_stack;

void		ft_swap(t_stack *stack, char *move);
void		ft_push(t_stack *stk_src, t_stack *stk_dst, char *move);
void		ft_swap_s(t_stack *stack_a, t_stack *stack_b);
void		ft_rotate(t_stack *stack, char *move);
void		ft_reverse_rotate(t_stack *stack, char *move);
void		ft_rotate_a_b(t_stack *stack_a, t_stack *stack_b);
void		ft_reverse_rotate_a_b(t_stack *stack_a, t_stack *stack_b);

void		ft_free_stack(t_stack *stack);
void		ft_free_chartab(char **tab);

t_stack		ft_init_stack(void);
int			ft_check_arg(t_stack *stk_a, int argc, char **argv);

long long	ft_not_a_atoll(const char *nptr);
void		ft_print_move(char *move);
int			ft_is_stack_sorted(t_stack *stk);
int			ft_make_circular(t_stack *stk);
void		ft_addfront_circular(t_list **lst, t_list *new);
int			ft_contain_char(char *str);
void		ft_update_min_max(t_stack *stk);
int			ft_abs(int nb);
void		ft_ascend_in_a_b(t_stack *stk_a, t_stack *stk_b, int nb);

int			ft_algo_main(t_stack *stk_a, t_stack *stk_b);

int			ft_check_special_cases(t_stack *stk_a, t_stack *stk_b);
void		ft_case3(t_stack *stk);

int			ft_find_elem(t_stack *stk, int nb);
void		ft_put_a_to_top(t_stack *stk, int nb);

void		ft_final_insert(t_stack *stk_a, t_stack *stk_b);

int			ft_put_in_b(t_stack *stk_a, t_stack *stk_b);

int			ft_cost_to_top(t_stack *stk, int nb);
void		ft_get_target_and_cost(t_stack *stk_a, t_stack *stk_b);
int			ft_select_minimum_cost(t_stack *stk_a);
int			ft_get_near(t_stack *stk, int nb);

void		ft_move_stk_a(t_stack *stk_a, int nb_moves);

#endif