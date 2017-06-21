/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:27:00 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/17 15:58:05 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		check_accur(t_rule *p, int i, int flag)
{
	int		k;
	int		plus;
	int		space;

	plus = flag_plus(p) == 1 ? 1 : flag;
	space = plus == 1 ? 0 : flag_space(p);
	k = 1;
	while (p->width-- - plus - space > p->accur && k++)
		ft_putchar(' ');
	if ((plus || flag) && k++)
		flag == 1 ? ft_putchar('-') : ft_putchar('+');
	else if (space && k++)
		flag == 1 ? ft_putchar('-') : ft_putchar(' ');
	if (flag || plus || space)
		while (i++ <= (p->accur - plus - space) && k++)
			ft_putchar('0');
	else
		while (i++ < (p->accur - plus - space) && k++)
			ft_putchar('0');
	return (k);
}

int		check_width(t_rule *p, int i, int flag)
{
	int		k;
	int		zero;
	int		j;

	k = 1;
	j = 1;
	zero = flag_zero(p);
	if (i >= p->accur)
	{
		if (flag_plus(p) && zero && k++ && j++)
			flag == 1 ? ft_putchar('-') : ft_putchar('+');
		else if (flag == 1 && k++ && zero && j++)
			ft_putchar('-');
		else if (flag_space(p) && !flag && !flag_plus(p) && zero && k++)
			flag_space(p) && j++ ? ft_putchar(' ') : 0;
		flag_plus(p) && k == 1 ? k++ : 0;
		while ((i++ + k - 1) < p->width && j++)
			(zero && p->accur == 0) ? ft_putchar('0') : ft_putchar(' ');
		if ((flag_plus(p) || flag) && !zero && k == 2 && j++)
			flag == 1 ? ft_putchar('-') : ft_putchar('+');
	}
	else
		j = check_accur(p, i, flag);
	return (j - 1);
}

int		helper_int(t_rule *p, int i, char *str, int flag)
{
	int		k;

	if (i >= p->accur && i >= p->width)
		k = print_symb(p, str[0], flag);
	else
	{
		if (i < p->width)
			k = check_width(p, i, flag);
		else
		{
			k = print_symb(p, str[0], flag);
			while (i++ < p->accur)
				ft_putchar('0');
			i--;
		}
	}
	if (p->accur == -1 && !(ft_strcmp(str, "0")))
		p->width == 0 && i-- ? 0 : ft_putchar(' ');
	else
		ft_putstr(str);
	return (i + k);
}

int		print_int(t_rule *p, intmax_t numb)
{
	int		i;
	int		flag;
	char	*str;

	flag = 0;
	if (numb < 0)
	{
		numb *= -1;
		flag = 1;
	}
	str = ft_itoa_base(numb, 10);
	i = ft_strlen(str);
	if (!flag_minus(p))
		i = helper_int(p, i, str, flag);
	else
		i = minus_int(p, i, str, flag);
	free(str);
	return (i);
}
