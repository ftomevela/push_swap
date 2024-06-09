/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:06:34 by ftome-ve          #+#    #+#             */
/*   Updated: 2024/06/07 21:02:01 by ftome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*newlast;

	if (!*stack || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	newlast = *stack;
	while (newlast->next->next != NULL)
		newlast = newlast->next;
	tmp = newlast->next;
	newlast->next = NULL;
	ft_lstadd_front(stack, tmp);
}

void	rra(t_stack **a, int check)
{
	rev_rotate(a);
	if (check == 0)
		my_write (1, "rra\n", 4);
}

void	rrb(t_stack **b, int check)
{
	rev_rotate(b);
	if (check == 0)
		my_write (1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int check)
{
	rev_rotate(a);
	rev_rotate(b);
	if (check == 0)
		my_write (1, "rrr\n", 4);
}
