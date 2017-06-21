/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:13:08 by efedorov          #+#    #+#             */
/*   Updated: 2016/12/04 13:41:10 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	j;

	if ((!(s1)) || (!(s2)))
		return (0);
	j = 0;
	while (s1[j] && j < (unsigned int)n)
	{
		if ((unsigned char)s1[j] - (unsigned char)s2[j])
			return (0);
		j++;
	}
	if ((unsigned char)s1[j] - (unsigned char)s2[j]
		&& (j != (unsigned int)n))
		return (0);
	else
		return (1);
}
