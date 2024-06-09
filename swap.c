/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:23:09 by ftome-ve          #+#    #+#             */
/*   Updated: 2024/06/07 21:02:45 by ftome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_stack **a, int check)
{
	swap(a);
	if (check == 0)
		my_write (1, "sa\n", 3);
}

void	sb(t_stack **b, int check)
{
	swap(b);
	if (check == 0)
		my_write (1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int check)
{
	swap(a);
	swap(b);
	if (check == 0)
		my_write (1, "ss\n", 3);
}
