/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:50:14 by ftome-ve          #+#    #+#             */
/*   Updated: 2024/06/09 17:30:30 by ftome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}

void	ra(t_stack **a, int check)
{
	rotate(a);
	if (check == 0)
		write (1, "ra\n", 3);
}

void	rb(t_stack **b, int check)
{
	rotate(b);
	if (check == 0)
		write (1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int check)
{
	rotate(a);
	rotate(b);
	if (check == 0)
		write (1, "rr\n", 3);
}
