/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:32:52 by efedorov          #+#    #+#             */
/*   Updated: 2016/11/30 13:08:55 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dest,
					const void *restrict src, int c, size_t n)
{
	char	*s1;
	char	*s2;
	int		i;

	i = 0;
	s1 = (char*)dest;
	s2 = (char*)src;
	while (n)
	{
		s1[i] = s2[i];
		if (s2[i] == c)
			return (&s1[i + 1]);
		i++;
		n--;
	}
	return (NULL);
}
