/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:56:51 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/21 19:04:59 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_case_u(char *str, t_rule *p)
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
				p->accur > 0 ? ft_putchar('0') : ft_putchar(' ');
			else if (p->width <= 0)
				p->accur <= 0 ? j-- : ft_putchar(' ');
			j++;
			return (j);
		}
		else
			ft_putchar(str[j]);
		j++;
	}
	return (j);
}

int		minus_u(t_rule *p, int i, char *str)
{
	int		k;

	k = 1;
	while (i++ < p->accur && k++)
		ft_putchar('0');
	k += print_case_u(str, p);
	while (k <= p->width)
	{
		ft_putchar(' ');
		k++;
	}
	return (k - 1);
}

int		plus_u(t_rule *p, int i, char *str)
{
	int		k;

	k = 1;
	if (flag_zero(p) && p->accur == 0)
		while (i++ < p->width && k++)
			ft_putchar('0');
	else if (i < p->width)
	{
		i = i < p->accur ? p->accur : i;
		while (i++ < p->width && k++)
			ft_putchar(' ');
	}
	i = ft_strlen(str);
	while (i++ < p->accur && k++)
		ft_putchar('0');
	k += print_case_u(str, p);
	return (k - 1);
}

int		print_u(t_rule *p, uintmax_t numb)
{
	int		k;
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa_base_hex(numb, 10);
	i = ft_strlen(str);
	if (flag_minus(p))
		k = minus_u(p, i, str);
	else
		k = plus_u(p, i, str);
	free(str);
	return (k);
}
