/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_lis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 06:36:29 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/03/24 16:04:39 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_on_lis(t_stack *a, t_lis **f_stack)
{
	int		i;
	t_lis	*lis;

	i = 0;
	while (f_stack[i] != NULL)
	{
		if (i == 0 || lis->level <= f_stack[i]->level)
			lis = f_stack[i];
		i++;
	}
	i = lis->nbr;
	while (a != NULL)
	{
		a->lis = 0;
		if (lis != NULL && a->number == lis->nbr)
		{
			if (lis->next != NULL)
				a->lis = (lis->next)->nbr;
			else
				a->lis = i;
			lis = lis->next;
		}
		a = a->next;
	}
}

void	ft_get_lis(t_stack *a, int size)
{
	int		i;
	t_lis	**f_stack;

	f_stack = ft_lis_stack(a, size);
	while (size >= 0)
	{
		i = size;
		while (f_stack[i] != NULL)
		{
			if (f_stack[size]->nbr < f_stack[i]->nbr)
			{
				if (f_stack[size]->level <= f_stack[i]->level)
				{
					f_stack[size]->next = f_stack[i];
					f_stack[size]->level = f_stack[i]->level +1;
				}
			}
			i++;
		}
		size--;
	}
	ft_on_lis(a, f_stack);
	free_lis(f_stack, NULL);
}

t_stack	*ft_make_stack(char **av, int ac, int *i)
{
	t_stack	*a;

	a = ft_make_list(av, ac, i);
	ft_get_lis(a, *i);
	return (a);
}
