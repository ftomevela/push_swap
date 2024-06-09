/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:14:15 by ftome-ve          #+#    #+#             */
/*   Updated: 2024/06/09 16:33:46 by ftome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_position(t_stack *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (stack == NULL)
		return ;
	centerline = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= centerline)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		++i;
	}
}

void	get_target(t_stack *a, t_stack *b)
{
	t_stack	*stack_a;
	t_stack	*target_node;
	int		best_match;

	while (b)
	{
		best_match = INT_MAX;
		stack_a = a;
		while (stack_a)
		{
			if (stack_a->content > b->content && stack_a->content < best_match)
			{
				best_match = stack_a->content;
				target_node = stack_a;
			}
			stack_a = stack_a->next;
		}
		if (INT_MAX == best_match)
			b->target = find_smaller(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	get_price(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while (b)
	{
		b->push_price = b->position;
		if (b->above_median == 0)
			b->push_price = size_b - (b->position);
		if (b->target->above_median == 1)
			b->push_price += b->target->position;
		else
			b->push_price += size_a - (b->target->position);
		b = b->next;
	}
}

void	get_cheapest(t_stack *b)
{
	int		best_match_value;
	t_stack	*best_match_node;

	if (b == NULL)
		return ;
	best_match_value = INT_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = 1;
}

void	get_index(t_stack **a)
{
	t_stack	*indicator;
	t_stack	*biggestindicator;
	int		stacksize;
	int		biggest;

	stacksize = ft_lstsize(*a);
	while (stacksize-- > 0)
	{
		indicator = *a;
		biggest = INT_MIN;
		while (indicator)
		{
			if (indicator->index == 0 && indicator->content > biggest)
			{
				biggest = indicator->content;
				biggestindicator = indicator;
			}
			indicator = indicator->next;
		}
		biggestindicator->index = stacksize +1;
	}
}
