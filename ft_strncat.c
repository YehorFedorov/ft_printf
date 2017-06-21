/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:38:17 by efedorov          #+#    #+#             */
/*   Updated: 2016/11/30 13:10:31 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*dest;
	char	*src;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = s1;
	src = (char*)s2;
	while (dest[i])
		i++;
	while (src[j] && n > 0)
	{
		dest[i + j] = src[j];
		j++;
		n--;
	}
	dest[i + j] = '\0';
	return (dest);
}
