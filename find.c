/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:26:29 by ftome-ve          #+#    #+#             */
/*   Updated: 2024/06/04 19:49:26 by ftome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_higgest(t_stack *stack)
{
	t_stack	*higgest_indicator;
	int		higgest_a;

	if (stack == NULL)
		return (NULL);
	higgest_a = INT_MIN;
	while (stack)
	{
		if (stack->content > higgest_a)
		{
			higgest_a = stack->content;
			higgest_indicator = stack;
		}
		stack = stack->next;
	}
	return (higgest_indicator);
}

t_stack	*find_smaller(t_stack *stack)
{
	t_stack	*smaller_indicator;
	int		smallest;

	if (stack == NULL)
		return (NULL);
	smallest = INT_MAX;
	while (stack)
	{
		if (stack->content < smallest)
		{
			smallest = stack->content;
			smaller_indicator = stack;
		}
		stack = stack->next;
	}
	return (smaller_indicator);
}

t_stack	*find_cheapest(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
