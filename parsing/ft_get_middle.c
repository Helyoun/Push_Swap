/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_middle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:29:23 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/03/27 10:48:33 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	tmp = tab[size / 2];
	return (tmp);
}

int	ft_get_middle(t_stack *a, int size)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * size);
	if (array == NULL)
		ft_fe(&a);
	i = 0;
	while (i < size)
	{
		array[i] = a->number;
		i++;
		a = a->next;
	}
	i = ft_sort_int_tab(array, size);
	free(array);
	return (i);
}
