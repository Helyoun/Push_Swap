/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:32:23 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/01 18:42:14 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR 9999999999
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*target;
	int				lis;
	short			mtotop;
}	t_stack;

typedef struct s_lis
{
	int				nbr;
	int				level;
	struct s_lis	*next;
}	t_lis;

void	ft_sort_five(t_stack **a, t_stack **b, int i);
int		abs(int value);
void	ft_do_moves2(t_stack **a, t_stack **b, int a_m, int b_m);
t_stack	*ft_min(t_stack *a);
void	ft_algo(t_stack **a, t_stack **b, int middle, int i);
int		ft_stack_size(t_stack *stack);
t_stack	*ft_min_moves(t_stack *b);
int		min_m(t_stack *node, t_stack *target);
int		ft_get_middle(t_stack *a, int size);
void	ft_push_from_b(t_stack **a, t_stack **b);
void	ft_push_from_a(t_stack **a, t_stack **b, int middle);
void	ft_pf_b_to_a(t_stack **a, t_stack **b);
t_stack	*min_moves(t_stack *b);
void	ft_do_moves(t_stack **a, t_stack **b);
void	ft_m_before(t_stack **a, t_stack **b);
int		ft_g_llast(t_stack *a);
int		ft_lstack(t_stack *a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	ft_mtt_aab(t_stack *a, t_stack *b);
void	ft_get_target(t_stack *a, t_stack *b);
t_stack	*ft_make_stack(char **av, int ac, int *i);
void	ft_get_lis(t_stack *a, int size);
t_lis	**ft_lis_stack(t_stack *a, int size);
t_lis	*ft_m_lis_node(t_lis **lis, t_stack *a, int nbr);
void	free_lis(t_lis **lis, t_stack *a);
void	ft_move_to_top(t_stack *stack);
int		ft_check_stack(t_stack *stack);
long	ft_atoi(char **str);
int		ft_isod(int c);
int		ft_countword(char *str);
int		ft_strisvalid(char *str);
void	ft_split(char *str, t_stack **stack, int *len);
void	ft_make_node(int nb, t_stack **stack);
t_stack	*ft_make_list(char **av, int ac, int *len);
void	ft_free_list(t_stack **stack);
void	ft_fe(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **b, t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	pb_tt(t_stack **a, t_stack **b, int i);

#endif
