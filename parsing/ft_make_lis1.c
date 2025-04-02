/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_lis1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 06:36:16 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/03/21 06:43:50 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_lis(t_lis **lis, t_stack *a)
{
	int	i;

	i = 0;
	while (lis[i] != NULL)
	{
		free(lis[i]);
		i++;
	}
	free(lis);
	if (a != NULL)
		ft_fe(&a);
}

t_lis	*ft_m_lis_node(t_lis **lis, t_stack *a, int nbr)
{
	t_lis	*node;

	node = malloc(sizeof(t_lis));
	if (node == NULL)
		free_lis(lis, a);
	node->nbr = nbr;
	node->next = NULL;
	node->level = 0;
	return (node);
}

t_lis	**ft_lis_stack(t_stack *a, int size)
{
	int		i;
	t_lis	**f_stack;
	t_stack	*save;

	f_stack = malloc(sizeof(t_lis *) * (size + 1));
	if (f_stack == NULL)
		ft_fe(&a);
	i = 0;
	save = a;
	while (i < size)
	{
		f_stack[i] = ft_m_lis_node(f_stack, save, a->number);
		a = a->next;
		i++;
	}
	f_stack[i] = NULL;
	return (f_stack);
}
