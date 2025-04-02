/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:07:07 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/03/27 11:01:45 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min_m(t_stack *node, t_stack *target)
{
	int	i;

	if (node->mtotop * target->mtotop >= 0)
	{
		if (abs(node->mtotop) > abs(target->mtotop))
			i = node->mtotop;
		else
			i = target->mtotop;
	}
	else
		i = abs(node->mtotop) + abs(target->mtotop);
	return (abs(i));
}

t_stack	*ft_min_moves(t_stack *b)
{
	int		i;
	int		j;
	t_stack	*node;

	node = b;
	while (b != NULL)
	{
		i = min_m(b, b->target);
		j = min_m(node, node->target);
		if (i < j)
			node = b;
		b = b->next;
	}
	return (node);
}

void	ft_do_moves2(t_stack **a, t_stack **b, int a_m, int b_m)
{
	while (a_m > 0)
	{
		ra(a);
		a_m--;
	}
	while (b_m > 0)
	{
		rb(b);
		b_m--;
	}
	while (a_m < 0)
	{
		rra(a);
		a_m++;
	}
	while (b_m < 0)
	{
		rrb(b);
		b_m++;
	}
}

void	ft_do_moves(t_stack **a, t_stack **b)
{
	t_stack	*node;
	int		a_m;
	int		b_m;

	node = ft_min_moves(*b);
	b_m = node->mtotop;
	a_m = (node->target)->mtotop;
	while (a_m * b_m > 0 && a_m > 0 && b_m > 0)
	{
		rr(a, b);
		a_m--;
		b_m--;
	}
	while (a_m * b_m > 0 && a_m < 0 && b_m < 0)
	{
		rrr(a, b);
		a_m++;
		b_m++;
	}
	ft_do_moves2(a, b, a_m, b_m);
}
