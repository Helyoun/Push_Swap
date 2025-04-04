/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:22:36 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/04 01:12:17 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack **a)
{
	if (ft_check_stack(*a) == 0)
		ra(a);
}

void	ft_sort_tree(t_stack **a)
{
	int	head;
	int	body;
	int	tail;

	head = (*a)->number;
	body = ((*a)->next)->number;
	tail = (((*a)->next)->next)->number;
	if (ft_check_stack (*a) == 1)
		return ;
	if ((head > body && body > tail)
		|| (head < tail && body > tail) || (head > body && head < tail))
		sa(a);
	head = (*a)->number;
	body = ((*a)->next)->number;
	tail = (((*a)->next)->next)->number;
	if (tail < head && tail > body)
		ra(a);
	else if (head > tail && head < body)
		rra(a);
}

void	ft_sort_five(t_stack **a, t_stack **b, int i)
{
	while (i > 3)
	{
		pb(b, a);
		i--;
	}
	ft_sort_tree(a);
	if (b != NULL)
		ft_push_from_b(a, b);
}

int	main(int ac, char **av)
{
	int		i;
	int		middle;
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	i = 0;
	a = ft_make_stack (av, ac, &i);
	b = NULL;
	if (ft_check_stack(a) == 0)
	{
		middle = ft_get_middle(a, i);
		b = NULL;
		ft_algo(&a, &b, middle, i);
	}
	ft_free_list(&a);
}
