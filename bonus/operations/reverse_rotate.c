/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:27:29 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/03/28 10:59:35 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*save;

	save = *stack;
	while ((*stack)->next != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
	}
	tmp->next = NULL;
	(*stack)->next = save;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

int	ft_check_rev_rotate(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "rrr\n") == 0)
	{
		rrr(a, b);
		return (1);
	}
	else if (ft_strcmp(line, "rra\n") == 0)
	{
		rra(a);
		return (1);
	}
	else if (ft_strcmp(line, "rrb\n") == 0)
	{
		rrb(b);
		return (1);
	}
	return (0);
}
