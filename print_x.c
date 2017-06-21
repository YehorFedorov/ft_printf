/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:04:19 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/21 19:27:46 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_case(char *str, t_rule *p)
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
			p->type == 'x' ? ft_putchar(ft_tolower(str[j])) :
				ft_putchar(ft_toupper(str[j]));
		j++;
	}
	return (j);
}

int		minus_x(t_rule *p, int i, char *str)
{
	int		k;
	int		hash;

	k = 1;
	hash = flag_hash(p);
	if (hash)
	{
		k += 2;
		i += 2;
		p->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
	}
	while (i++ < p->accur && k++)
		ft_putchar('0');
	k += print_case(str, p);
	while (k <= p->width)
	{
		ft_putchar(' ');
		k++;
	}
	return (k - 1);
}

int		plus_x(t_rule *p, int i, char *str)
{
	int		k;

	k = 1;
	if (flag_hash(p) && ft_strcmp(str, "0"))
	{
		k += 2;
		i = i < p->accur ? p->accur : i;
		while (i++ + 2 < p->width && !(flag_zero(p)) && k++)
			ft_putchar(' ');
		p->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
		i++;
	}
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
	return (k - 1);
}

int		print_x(t_rule *p, uintmax_t numb)
{
	int		k;
	int		i;
	char	*str;

	str = ft_itoa_base_hex(numb, 16);
	i = ft_strlen(str);
	if (flag_minus(p))
		k = minus_x(p, i, str);
	else
	{
		k = plus_x(p, i, str);
		k += print_case(str, p);
	}
	free(str);
	return (k);
}
