/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:50:02 by ftome-ve          #+#    #+#             */
/*   Updated: 2024/06/07 21:01:27 by ftome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **orig, t_stack **dest)
{
	t_stack	*tmp;

	tmp = (*orig)->next;
	(*orig)->next = *dest;
	*dest = *orig;
	*orig = tmp;
}

void	pa(t_stack **b, t_stack **a, int check)
{
	push (b, a);
	if (check == 0)
		my_write (1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int check)
{
	push(a, b);
	if (check == 0)
		my_write (1, "pb\n", 3);
}
