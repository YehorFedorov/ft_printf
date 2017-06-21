/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:32:08 by efedorov          #+#    #+#             */
/*   Updated: 2016/11/30 12:40:40 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s2 = (unsigned char*)src;
	s1 = (unsigned char*)dest;
	while (n)
	{
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	return (dest);
}
