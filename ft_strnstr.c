/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:37:24 by efedorov          #+#    #+#             */
/*   Updated: 2016/12/01 12:13:27 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t i)
{
	const char	*s1;
	const char	*s2;
	size_t		j;
	size_t		k;

	j = 0;
	if (!*find)
		return (char*)(str);
	while (*str && j < i)
	{
		s1 = str;
		s2 = find;
		k = j;
		while (*s1 && *s2 && !(*s1 - *s2) && k < i)
		{
			s1++;
			s2++;
			k++;
		}
		if (!*s2)
			return (char*)(str);
		j++;
		str++;
	}
	return (NULL);
}
