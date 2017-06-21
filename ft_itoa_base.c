/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 13:27:59 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/21 19:09:02 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	f_hex(uintmax_t value, int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789ABCDEF";
	if (value != 0)
	{
		if (value >= (unsigned int)base)
			f_hex(value / base, base, str, i);
		str[(*i)++] = tmp[(value % base)];
	}
	else
		str[(*i)++] = '0';
}

char	*ft_itoa_base_hex(uintmax_t value, int base)
{
	char	*s;
	int		i;

	i = 0;
	if (base < 2 || base > 16 || !(s = (char *)malloc(32)))
		return (0);
	f_hex(value, base, s, &i);
	s[i] = '\0';
	return (s);
}

void	f(intmax_t value, int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789ABCDEF";
	if (value <= -base || value >= base)
		f(value / base, base, str, i);
	str[(*i)++] = tmp[(value % base) < 0 ? -(value % base) : (value % base)];
}

char	*ft_itoa_base(intmax_t value, int base)
{
	char	*s;
	int		i;

	i = 0;
	if (base < 2 || base > 16 || !(s = (char *)malloc(32)))
		return (0);
	if (base == 10 && value < 0)
		s[i++] = '-';
	f(value, base, s, &i);
	s[i] = '\0';
	return (s);
}
