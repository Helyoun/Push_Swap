/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:52:45 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/04 01:17:46 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_check_moves(char *line, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (line == NULL)
		return ;
	i = i + ft_check_push(line, a, b);
	i = i + ft_check_rev_rotate(line, a, b);
	i = i + ft_check_rotate(line, a, b);
	i = i + ft_check_swap(line, a, b);
	if (i == 0)
	{
		write(2, "Error\n", 6);
		free(line);
		ft_free_list(a);
		ft_free_list(b);
		exit(1);
	}
	free(line);
}
