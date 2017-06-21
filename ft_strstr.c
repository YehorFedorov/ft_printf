/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:52:09 by efedorov          #+#    #+#             */
/*   Updated: 2016/11/29 14:22:12 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	const char	*s1;
	const char	*s2;

	if (!*find)
		return (char*)(str);
	while (*str)
	{
		s1 = str;
		s2 = find;
		while (*s1 && *s2 && !(*s1 - *s2))
		{
			s1++;
			s2++;
		}
		if (!*s2)
			return (char*)(str);
		str++;
	}
	return (0);
}
