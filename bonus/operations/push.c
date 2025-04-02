/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:10:28 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/03/28 10:13:59 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*node;

	node = *stack2;
	*stack2 = (*stack2)->next;
	node->next = *stack1;
	*stack1 = node;
}

void	pb(t_stack **b, t_stack **a)
{
	if (*a == NULL )
		return ;
	push(b, a);
}

void	pa(t_stack **a, t_stack **b)
{
	if (*b == NULL)
		return ;
	push(a, b);
}

int	ft_check_push(char *line, t_stack **a, t_stack **b)
{
	if (line != NULL && ft_strcmp(line, "pa\n") == 0)
	{
		pa(a, b);
		return (1);
	}
	else if (line != NULL && ft_strcmp(line, "pb\n") == 0)
	{
		pb(b, a);
		return (1);
	}
	return (0);
}
