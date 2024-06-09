/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:42:36 by ftome-ve          #+#    #+#             */
/*   Updated: 2024/06/09 16:31:39 by ftome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!is_sorted(&a))
		push_swap(&a, &b);
	ft_lstclear(&a);
	free(a);
	if (argc == 2)
		ft_free_split(argv);
}
