/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:10:08 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/03/27 09:35:55 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	ft_move_to_top(t_stack *stack)
{
	int		i;
	int		len;

	len = ft_stack_size(stack);
	i = 0;
	while (stack != NULL)
	{
		if (len == 1 || i < len / 2)
			stack->mtotop = i;
		else
			stack->mtotop = i - len ;
		i++;
		stack = stack->next;
	}
}

void	ft_mtt_aab(t_stack *a, t_stack *b)
{
	ft_move_to_top(a);
	ft_move_to_top(b);
}
