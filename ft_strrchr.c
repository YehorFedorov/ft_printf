/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:39:04 by efedorov          #+#    #+#             */
/*   Updated: 2016/11/30 13:05:09 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		j;

	j = 0;
	while (s[j])
		j++;
	if (j == 0)
		return (NULL);
	while (j >= 0)
	{
		if (s[j] == (char)c)
			return ((char*)&s[j]);
		j--;
	}
	return (NULL);
}
