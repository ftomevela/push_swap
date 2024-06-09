/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:46:52 by ftome-ve          #+#    #+#             */
/*   Updated: 2024/06/07 21:52:53 by ftome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_stack *a)
{
	ft_lstclear(&a);
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

int	is_correct(char **argv, t_stack **a)
{
	int	number;
	int	i;

	i = 0;
	if (argv == NULL || argv[i] == NULL)
		error(*a);
	if ((argv[i][0] < 48 || argv[i][0] > 57) &&
		!(argv[i][0] == '+' || argv[i][0] == '-' ))
		error(*a);
	if ((argv[i][0] == '+' || argv[i][0] == '-')
		&& !(argv[i][1] >= 48 && argv[i][1] <= 57))
		error(*a);
	number = ft_atoi(argv[i], *a);
	if (number < INT_MIN || number > INT_MAX)
		error(*a);
	return (number);
}

void	is_not_repeated(int numb, t_stack **a)
{
	t_stack	*current;

	current = *a;
	while (current != NULL)
	{
		if (current->content == numb)
			error(*a);
		current = current->next;
	}
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*prox;

	temp = *lst;
	while (temp != NULL)
	{
		prox = temp->next;
		free(temp);
		temp = prox;
	}
	*lst = NULL;
}
