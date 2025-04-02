/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_lis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:39:29 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/03/27 11:39:38 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_it_is_onlis(t_stack *a, int	*lis, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (a->number == lis[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_lstack(t_stack *a)
{
	while (a != NULL)
	{
		if (a->lis == 0)
			return (0);
		a = a->next;
	}
	return (1);
}
