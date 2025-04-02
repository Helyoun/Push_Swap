/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 08:26:12 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/01 17:57:04 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_first_nbrs(t_stack *a, t_stack *node)
{
	while (a != NULL)
	{
		if (a->number > node->number)
		{
			if (node->target == NULL || a->number < node->target->number)
				node->target = a;
		}
		a = a->next;
	}
}

void	ft_last_nbrs(t_stack *a, t_stack *node)
{
	t_stack	*target;

	node->target = NULL;
	while (a != NULL)
	{
		if (a->number < node->number)
		{
			target = node->target;
			if (target == NULL || a->number < target->number)
				node->target = a ;
		}
		a = a->next;
	}
}

void	ft_get_target(t_stack *a, t_stack *b)
{
	while (b != NULL)
	{
		b->target = NULL;
		ft_first_nbrs(a, b);
		if (b->target == NULL)
			ft_last_nbrs(a, b);
		b = b->next;
	}
}
