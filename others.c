/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:11:30 by ftome-ve          #+#    #+#             */
/*   Updated: 2024/06/05 16:06:07 by ftome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	my_write(int fd, const void *buf, size_t count)
{
	return (write(fd, buf, count));
}

void	process_arguments(char **argv, t_stack **a)
{
	t_stack	*new_node;
	int		i;
	int		numb;

	i = 0;
	while (argv[i])
	{	
		numb = is_correct(&argv[i], a);
		is_not_repeated(numb, a);
		new_node = ft_lstnew(&numb);
		ft_lstadd_back(a, new_node);
		i++;
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len > 0)
	{
		*ptr++ = c;
		len--;
	}
	return (b);
}
