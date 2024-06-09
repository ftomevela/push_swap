/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:42:18 by ftome-ve          #+#    #+#             */
/*   Updated: 2024/06/04 20:16:47 by ftome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

// char	*ft_strdup(const char *str)
// {
// 	size_t	len;
// 	char	*str2;

// 	len = ft_strlen(str);
// 	str2 = (char *) malloc(len + 1);
// 	if (str2 == NULL)
// 		return NULL;
// 	ft_strlcpy(str2, str, (len + 1));
// 	return (str2);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	sub = NULL;
	if (!s)
		return (NULL);
	if (start > (unsigned int) ft_strlen(s))
		return (ft_strdup(""));
	if ((unsigned int) ft_strlen(s + start) < len)
		len = ft_strlen (s + start);
	sub = malloc ((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, (s + start), (len +1));
	return (sub);
}
