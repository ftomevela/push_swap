/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:24:05 by ftome-ve          #+#    #+#             */
/*   Updated: 2024/06/09 16:30:51 by ftome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, t_stack *a)
{
	int			i;
	int			signo;
	long int	number;

	i = 0;
	signo = 1;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		signo = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number *= 10;
		number += str[i] - 48;
		if ((signo == 1 && number > INT_MAX)
			|| (signo == -1 && - number < INT_MIN))
			error(a);
		i++;
	}
	if (str[i] != '\0')
		error(a);
	return (number * signo);
}

int	ft_counterwords(char const *s, char c)
{
	int		count_words;
	char	comp;

	comp = c;
	count_words = 0;
	while (*s)
	{
		if (*s != comp && (*(s + 1) == comp || *(s + 1) == '\0'))
		{
			count_words++;
		}
		s++;
	}
	return (count_words);
}

char	**ft_splitwords(char **split, char const *s, char c)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	p = 0;
	while (i <= ft_strlen(s))
	{
		while (s[i] && s[i] != c)
		{
			i++;
			j++;
		}
		if ((i == ft_strlen(s) || s[i] == c) && j > 0)
		{
			split[p] = ft_substr(s, i - j, j);
			j = 0;
			p++;
		}
		i++;
	}
	split[p] = NULL;
	return (split);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	int		count_words;
	char	**split;

	count_words = ft_counterwords(s, c);
	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (count_words + 1));
	if (!split)
		return (NULL);
	if (!ft_splitwords(split, s, c))
	{
		ft_free_split(split);
		return (NULL);
	}
	return (split);
}
