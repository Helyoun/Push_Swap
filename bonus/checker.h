/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:32:23 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/02 09:15:51 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define ERROR 9999999999
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*target;
	int				lis;
	short			mtotop;
}	t_stack;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*content ;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_strdup(char **buffer, int *fd);
char	*ft_changestr(char **buffer, size_t i);
int		ft_strlen(t_list *ls);
void	gnl_free_list(t_list **ls);
void	ft_check(int read_byte, t_list **ls, char **buffer, int *fd);

int		ft_check_swap(char *line, t_stack **a, t_stack **b);
int		ft_check_rotate(char *line, t_stack **a, t_stack **b);
int		ft_check_rev_rotate(char *line, t_stack **a, t_stack **b);
int		ft_check_push(char *line, t_stack **a, t_stack **b);
t_stack	*ft_make_list(char **av, int ac, int *len);
int		ft_strcmp(char *s1, char *s2);
void	ft_fe(t_stack **stack);
void	ft_split(char *str, t_stack **stack, int *len);
void	ft_free_list(t_stack **stack);
long	ft_atoi(char **str);
int		ft_isod(int c);
int		ft_check_stack(t_stack *stack);
void	ft_check_moves(char *line, t_stack **a, t_stack **b);
int		ft_strisvalid(char *str);
#endif
