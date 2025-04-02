/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:28:44 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/03/28 10:17:31 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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
}

void	rb(t_stack **b)
{
	if (*b != NULL && (*b)->next != NULL)
		rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	if (*a == NULL || *b == NULL)
		return ;
	rotate(a);
	rotate(b);
}

int	ft_check_rotate(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "ra\n") == 0)
	{
		ra(a);
		return (1);
	}
	else if (ft_strcmp(line, "rb\n") == 0)
	{
		rb(b);
		return (1);
	}
	else if (ft_strcmp(line, "rr\n") == 0)
	{
		rr(a, b);
		return (1);
	}
	return (0);
}
