/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 06:38:15 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/02 09:30:10 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isod(int c)
{
	if (c == '-' || c == '+')
		return (2);
	else if (c >= '0' && c <= '9')
		return (1);
	if (c == 32 || c == 0)
		return (0);
	return (-1);
}

long	ft_atoi(char **str)
{
	long	nb;
	int		s;

	nb = 0;
	s = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			s = -1;
		*str = *str + 1;
	}
	if (ft_isod(**str) != 1)
		return (ERROR);
	while (**str >= '0' && **str <= '9')
	{
		nb = nb * 10 + (**str - '0');
		if (nb > -INT_MIN)
			return (ERROR);
		*str = *str + 1;
	}
	return (nb * s);
}

int	ft_strisvalid(char *str)
{
	int	i;

	i = 0;
	while (*str != 0)
	{
		if (ft_isod(*str) == 1 || ft_isod(*str) == 2)
			i++;
		if (ft_isod(*str) == -1
			|| (ft_isod(*str) == 1 && ft_isod(*(str + 1)) == 2))
			return (0);
		str++;
	}
	if (i == 0)
		return (0);
	return (1);
}

void	ft_free_list(t_stack **stack)
{
	t_stack	*save ;

	while ((*stack) != NULL)
	{
		save = (*stack)->next;
		free (*stack);
		*stack = save ;
	}
}
