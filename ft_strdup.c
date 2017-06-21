/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:36:56 by efedorov          #+#    #+#             */
/*   Updated: 2016/11/30 13:58:44 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;

	i = 0;
	if ((dst = (char*)malloc(sizeof(*dst) * ft_strlen(s1) + 1)) != NULL)
	{
		while (i < ft_strlen(s1))
		{
			dst[i] = s1[i];
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	else
		return (NULL);
}
