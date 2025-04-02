/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:28:16 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/03/28 10:15:25 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	swap(t_stack **stack)
{
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next = *stack;
	*stack = second;
}

void	sa(t_stack **a)
{
	if (*a == NULL)
		return ;
	swap(a);
}

void	sb(t_stack **b)
{
	if (*b == NULL)
		return ;
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}

int	ft_check_swap(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
	{
		sa(a);
		return (1);
	}
	else if (ft_strcmp(line, "sb\n") == 0)
	{
		sb(b);
		return (1);
	}
	else if (ft_strcmp(line, "ss\n") == 0)
	{
		ss(a, b);
		return (1);
	}
	return (0);
}
