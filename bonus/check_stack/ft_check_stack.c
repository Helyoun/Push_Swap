/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:39:54 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/03/28 10:13:09 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_check_stack(t_stack *stack)
{
	int	i;

	if (stack == NULL)
		return (1);
	i = stack->number;
	while (stack != NULL)
	{
		if (stack->number < i)
			return (0);
		i = stack->number;
		stack = stack->next;
	}
	return (1);
}
