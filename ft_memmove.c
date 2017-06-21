/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:29:42 by efedorov          #+#    #+#             */
/*   Updated: 2016/11/30 12:53:42 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	if (len)
	{
		s1 = (char*)dest;
		s2 = (char*)src;
		if (s2 < s1)
		{
			s1 += len;
			s2 += len;
			while (len)
			{
				*--s1 = *--s2;
				len--;
			}
		}
		else
		{
			while (len--)
				*s1++ = *s2++;
		}
	}
	return (dest);
}
