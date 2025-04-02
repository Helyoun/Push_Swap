/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 06:37:37 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/02 22:17:59 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_make_list(char **av, int ac, int *len)
{
	int		i;
	t_stack	*stack;

	i = 1;
	stack = NULL;
	*len = 0;
	while (i < ac)
	{
		if (ft_strisvalid(av[i]) == 0)
			ft_fe(&stack);
		else
			ft_split(av[i], &stack, len);
		i++;
	}
	if (stack == NULL)
		ft_fe(&stack);
	return (stack);
}

void	ft_checknbr(t_stack **stack, t_stack *node, int nbr)
{
	if (nbr == node->number)
	{
		free(node);
		ft_fe(stack);
	}
}

void	ft_make_node(int nb, t_stack **stack)
{
	t_stack	*save ;
	t_stack	*node ;

	save = *stack ;
	node = malloc (sizeof(t_stack));
	if (node == NULL)
		ft_fe(stack);
	node->number = nb;
	node->next = NULL;
	if (*stack == NULL)
	{
		*stack = node ;
		return ;
	}
	while ((*stack)->next != NULL)
	{
		ft_checknbr(&save, node, (*stack)->number);
		*stack = (*stack)->next;
	}
	ft_checknbr(&save, node, (*stack)->number);
	(*stack)->next = node;
	*stack = save;
}

void	ft_fe(t_stack **stack)
{
	ft_free_list(stack);
	write(1, "Error\n", 6);
	exit(0);
}

void	ft_split(char *str, t_stack **stack, int *len)
{
	long	nb;

	while (*str != 0)
	{
		while (*str != 0 && ft_isod(*str) == 0)
			str++;
		if (*str != 0)
		{
			nb = ft_atoi(&str);
			if (nb > INT_MAX || nb < INT_MIN)
				ft_fe(stack);
			ft_make_node(nb, stack);
			*len = *len + 1;
		}
	}
}
