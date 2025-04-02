/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:21:23 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/01 20:05:19 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_min(t_stack *a)
{
	t_stack	*node;

	node = a;
	while (a != NULL)
	{
		if (a->number < node->number)
			node = a;
		a = a->next;
	}
	return (node);
}

void	ft_push_from_a(t_stack **a, t_stack **b, int middle)
{
	while (ft_lstack(*a) == 0 && ft_check_stack(*a) == 0)
	{
		if ((*a)->lis != 0)
			ra(a);
		else
		{
			pb(b, a);
			if ((*b)->number < middle)
				rb(b);
		}
	}
}

void	ft_push_from_b(t_stack **a, t_stack **b)
{
	while ((*b) != NULL)
	{
		ft_get_target(*a, *b);
		ft_mtt_aab(*a, *b);
		ft_do_moves(a, b);
		pa(a, b);
	}
}

void	ft_algo(t_stack **a, t_stack **b, int middle, int i)
{
	t_stack	*node;

	if (i > 5)
		ft_push_from_a(a, b, middle);
	if (i >= 3)
		ft_sort_five(a, b, i);
	ft_push_from_b(a, b);
	node = ft_min(*a);
	ft_move_to_top(*a);
	ft_do_moves2(a, b, node->mtotop, 0);
}
