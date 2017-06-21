/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:17:04 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/21 19:28:23 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_case_o(char *str, t_rule *p)
{
	int		j;
	int		hash;

	j = 0;
	hash = flag_hash(p);
	while (str[j])
	{
		if (!(ft_strcmp(str, "0")))
		{
			if (p->width == 0 && p->accur == 0 && !(hash))
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

int		minus_o(t_rule *p, int i, char *str)
{
	int		k;

	k = 1;
	if (flag_hash(p) && k++)
		ft_putchar('0');
	while (i++ < p->accur && k++)
		ft_putchar('0');
	k += print_case_o(str, p);
	while (k <= p->width)
	{
		ft_putchar(' ');
		k++;
	}
	return (k - 1);
}

int		plus_o(t_rule *p, int i, char *str)
{
	int		k;

	k = 1;
	if (flag_hash(p) && k++)
	{
		i = i < p->accur ? p->accur : i;
		while (i++ + 1 < p->width && !(flag_zero(p)) && k++)
			ft_putchar(' ');
		ft_putchar('0');
	}
	else if (flag_zero(p) && p->accur == 0)
		while (i++ < p->width && k++)
			ft_putchar('0');
	else if (i < p->width)
	{
		i = i < p->accur ? p->accur : i;
		while (i++ < p->width && k++)
			ft_putchar(' ');
	}
	i = ft_strlen(str);
	flag_hash(p) ? i++ : 0;
	while (i++ < p->accur && k++)
		ft_putchar('0');
	k += print_case_o(str, p);
	return (k - 1);
}

int		print_o(t_rule *p, uintmax_t numb)
{
	int		k;
	char	*str;
	int		i;

	str = ft_itoa_base_hex(numb, 8);
	i = ft_strlen(str);
	if (flag_minus(p))
		k = minus_o(p, i, str);
	else
		k = plus_o(p, i, str);
	free(str);
	return (k);
}
