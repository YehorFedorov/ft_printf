/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:51:34 by efedorov          #+#    #+#             */
/*   Updated: 2016/12/04 12:14:12 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char *s1, char *s2, int n)
{
	unsigned char	*dest;
	unsigned char	*src;
	int				i;

	dest = (unsigned char*)s1;
	src = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (++i < n && *dest == *src && *dest != '\0' && *src != '\0')
	{
		dest++;
		src++;
	}
	return (*dest - *src);
}
