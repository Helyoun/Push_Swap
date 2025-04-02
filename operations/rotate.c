/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:28:44 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/03/27 10:29:24 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*save;
	t_stack	*tmp;

	save = (*stack)->next;
	tmp = *stack ;
	while (tmp->next != NULL)
		tmp = tmp->next;
	(*stack)->next = NULL;
	tmp->next = *stack;
	*stack = save;
}

void	ra(t_stack **a)
{
	if (*a != NULL && (*a)->next != NULL)
		rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	if (*b != NULL && (*b)->next != NULL)
		rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	if (*a == NULL || *b == NULL)
		return ;
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
