/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:17:42 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/21 18:52:02 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_case_p(char *str, t_rule *p)
{
	int		j;

	j = 0;
	while (str[j])
	{
		if (!(ft_strcmp(str, "0")))
		{
			if (p->width == 0 && p->accur == 0)
				ft_putchar('0');
			else if (p->width > 0)
				ft_putchar('0');
			else if (p->width <= 0)
				p->accur <= 0 ? j-- : ft_putchar('0');
			j++;
			return (j);
		}
		else
			ft_putchar(ft_tolower(str[j]));
		j++;
	}
	return (j);
}

int		minus_p(t_rule *p, int i, char *str)
{
	int		k;

	k = 1;
	while (i++ < p->accur && k++)
		ft_putchar('0');
	k += print_case_p(str, p);
	while (k + 2 <= p->width)
	{
		ft_putchar(' ');
		k++;
	}
	return (k - 1);
}

int		plus_p(t_rule *p, int i, char *str)
{
	int		k;

	k = 1;
	if (flag_zero(p) && p->accur == 0)
		while (i++ < p->width && k++)
			ft_putchar('0');
	else if (i < p->width)
	{
		i = i < p->accur ? p->accur : i;
		while (i++ + 2 < p->width && k++)
			ft_putchar(' ');
	}
	ft_putstr("0x");
	i = ft_strlen(str);
	while (i++ < p->accur && k++)
		ft_putchar('0');
	k += print_case_p(str, p);
	return (k - 1);
}

int		print_p(t_rule *p, void *s)
{
	int		k;
	char	*str;
	int		i;

	str = ft_itoa_base_hex((uintmax_t)s, 16);
	i = ft_strlen(str);
	k = 2;
	if (flag_minus(p))
	{
		ft_putstr("0x");
		k += minus_p(p, i, str);
	}
	else
		k += plus_p(p, i, str);
	free(str);
	return (k);
}
