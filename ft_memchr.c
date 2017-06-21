/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:33:48 by efedorov          #+#    #+#             */
/*   Updated: 2016/12/04 12:40:40 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*dest = s;

	while (n-- != 0)
	{
		if (*dest == (unsigned char)c)
			return ((void*)dest);
		dest++;
	}
	return (0);
}
