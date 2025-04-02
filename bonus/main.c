/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:26:42 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/02 22:49:34 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	char	*line;

	if (ac == 1)
		return (0);
	i = 0;
	b = NULL;
	a = ft_make_list(av, ac, &i);
	while (1)
	{
		line = get_next_line(0);
		ft_check_moves(line, &a, &b);
		if (line == NULL)
			break ;
	}
	if (ft_check_stack(a) == 1 && b == NULL)
		write(1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	ft_free_list(&a);
	ft_free_list(&b);
}
