/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:39:07 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/21 19:11:34 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_symb(t_rule *p, char symb, int flag)
{
	int		k;

	k = 1;
	if (flag_space(p) && !flag_plus(p) && !flag && k++)
		ft_putchar(' ');
	else if (flag_plus(p) && !flag && k++)
		ft_putchar('+');
	else if (flag && symb != '-')
	{
		ft_putchar('-');
		k++;
	}
	return (k - 1);
}

int		minus_int(t_rule *p, int i, char *str, int flag)
{
	int		k;

	k = 1;
	k += print_symb(p, str[0], flag);
	while (i++ < p->accur && k++)
		ft_putchar('0');
	i = ft_strlen(str);
	if (p->accur == -1 && !ft_strcmp(str, "0"))
		p->width == 0 && i-- ? 0 : ft_putchar(' ');
	else
		ft_putstr(str);
	while ((i + k) <= p->width && k++)
		ft_putchar(' ');
	return (k - 1 + i);
}
