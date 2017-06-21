/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:54:09 by efedorov          #+#    #+#             */
/*   Updated: 2016/12/04 14:17:26 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(int n)
{
	int len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	multiply(int num, int len)
{
	int res;

	if (len <= 0)
		return (1);
	res = 1;
	while (len--)
		res *= num;
	return (res);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*res;
	int		j;

	len = length(n);
	if (n <= 0)
		res = (char*)malloc(sizeof(char) * (len + 2));
	else
		res = (char*)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	j = 0;
	if (n < 0 && ++j)
		res[0] = '-';
	if (n == 0 && ++j)
		res[0] = '0';
	while (--len >= 0)
	{
		if (n < 0)
			res[j++] = '0' - (n / multiply(10, len)) % 10;
		else
			res[j++] = '0' + (n / multiply(10, len)) % 10;
	}
	res[j] = 0;
	return (res);
}
