/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:34:57 by efedorov          #+#    #+#             */
/*   Updated: 2016/11/30 14:16:06 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = (char*)malloc(sizeof(*mem) * size + 1);
	while (mem == NULL)
		return (NULL);
	while (i <= size)
	{
		mem[i] = '\0';
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
