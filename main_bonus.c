/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:06:40 by ftome-ve          #+#    #+#             */
/*   Updated: 2024/06/09 16:21:19 by ftome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_check(t_stack **a, t_stack **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
	write (2, "error\n", 6);
	exit (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	checker(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "pa\n"))
		pa(b, a, 1);
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b, 1);
	else if (!ft_strcmp(line, "sa\n"))
		sa(a, 1);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, 1);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, 1);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a, 1);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, 1);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, 1);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, 1);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, 1);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, 1);
	else
		error_check(a, b);
}

void	process_checker(t_stack **a, t_stack **b)
{
	char	*line;
	int		size_a;

	size_a = ft_lstsize(*a);
	line = get_next_line(0);
	while (line)
	{
		checker(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && size_a == ft_lstsize(*a))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2 && !argv[1][0])
		error(a);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (argc >= 3)
		argv = argv + 1;
	process_arguments(argv, &a);
	process_checker(&a, &b);
	ft_lstclear(&a);
	if (argc == 2)
		ft_free_split(argv);
}
