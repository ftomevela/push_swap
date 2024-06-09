/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:17:13 by ftome-ve          #+#    #+#             */
/*   Updated: 2024/06/09 16:43:31 by ftome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_check(t_stack **current)
{
	t_stack	*higgest;

	if (is_sorted(current))
		return ;
	higgest = find_higgest(*current);
	if (*current == higgest)
		ra(current, 0);
	else if ((*current)->next == higgest)
		rra(current, 0);
	if ((*current)->next && (*current)->content > (*current)->next->content)
		sa(current, 0);
}

int	is_sorted(t_stack **a)
{
	t_stack	*current;

	current = *a;
	if (current == NULL || current->next == NULL)
		return (1);
	else
	{
		while (current->next != NULL)
		{
			if (current->content > current->next->content)
				return (0);
			current = current->next;
		}
	}
	return (1);
}

void	first_moves(t_stack **a, t_stack **b)
{
	int	size;

	size = (ft_lstsize(*a) / 2);
	get_index(a);
	while (ft_lstsize(*a) > size + 1)
	{
		if ((*a)->index > size)
			ra(a, 0);
		else
			pb(a, b, 0);
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;

	smallest = *a;
	if (ft_lstsize(*a) == 3)
		first_check(a);
	if (ft_lstsize(*a) > 3)
		first_moves(a, b);
	while (ft_lstsize(*a) > 3)
		pb(a, b, 0);
	first_check(a);
	while (*b)
	{
		initialize(a, b);
		moves(a, b);
	}
	get_position(*a);
	smallest = find_smaller(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, 0);
	else
		while (*a != smallest)
			rra(a, 0);
}

void	initialize(t_stack **a, t_stack **b)
{
	get_position(*a);
	get_position(*b);
	get_target(*a, *b);
	get_price(*a, *b);
	get_cheapest(*b);
}
