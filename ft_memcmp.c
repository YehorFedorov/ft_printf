/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:30:43 by efedorov          #+#    #+#             */
/*   Updated: 2016/11/29 14:19:30 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	dest;
	unsigned char	src;

	while (n-- > 0)
	{
		dest = *(unsigned char*)s1;
		src = *(unsigned char*)s2;
		if (dest != src)
			return (dest - src);
		s1++;
		s2++;
	}
	return (0);
}
