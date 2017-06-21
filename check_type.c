/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 11:21:13 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/21 18:06:03 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		check_flag(t_rule *p)
{
	int		i;
	int		flag;

	i = -1;
	flag = 0;
	while (p->flag[++i])
	{
		if (p->flag[i] == '0' && flag == 0)
			flag = 1;
		else if ((p->flag[i] == '0' || p->flag[i] == '-') && flag != 0)
			flag = 3;
		else if (p->flag[i] == '-' && flag == 0)
			flag = 2;
	}
	return (flag);
}

int		print_char(t_rule *p, char c)
{
	int		count;
	int		flag;

	count = 1;
	flag = check_flag(p);
	count = p->width != 0 ? p->width : 1;
	if (flag == 2 || flag == 3)
	{
		ft_putchar(c);
		while (--p->width > 0)
			ft_putchar(' ');
	}
	else if (flag == 1)
	{
		while (--p->width > 0)
			ft_putchar('0');
		ft_putchar(c);
	}
	else if (flag == 0)
	{
		while (--p->width > 0)
			ft_putchar(' ');
		ft_putchar(c);
	}
	return (count);
}

int		print_inn_type(t_rule *p)
{
	int		count;
	int		flag;

	count = 1;
	flag = check_flag(p);
	count = p->width != 0 ? p->width : 1;
	if (flag == 2 || flag == 3)
	{
		ft_putchar(p->type);
		while (--p->width > 0)
			ft_putchar(' ');
	}
	else if (flag == 1)
	{
		while (--p->width > 0)
			ft_putchar('0');
		ft_putchar(p->type);
	}
	else if (flag == 0)
	{
		while (--p->width > 0)
			ft_putchar(' ');
		ft_putchar(p->type);
	}
	return (count);
}

int		check_type(t_rule *p, va_list ar)
{
	if (p->type == 's' || p->type == 'S')
		return (print_string(p, va_arg(ar, char*)));
	else if (p->type == 'd' || p->type == 'i' || p->type == 'D')
		return (check_len(p->l, ar, p));
	else if (p->type == 'p')
		return (print_p(p, va_arg(ar, void*)));
	else if (p->type == 'c' || p->type == 'C')
		return (print_char(p, va_arg(ar, int)));
	else if (p->type == 'o' || p->type == 'O')
		return (check_len_o(p->l, ar, p));
	else if (p->type == 'x' || p->type == 'X')
		return (check_len_x(p->l, ar, p));
	else if (p->type == 'u' || p->type == 'U')
		return (check_len_u(p->l, ar, p));
	else if (p->type == 0)
		return (0);
	else
		return (print_inn_type(p));
	return (0);
}
