/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:55:08 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/22 14:53:07 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	reset_rules(t_rule *p)
{
	p->flag[0] = 0;
	p->flag[1] = 0;
	p->flag[2] = 0;
	p->flag[3] = 0;
	p->flag[4] = 0;
	p->width = 0;
	p->accur = 0;
	p->type = 0;
	p->l = 0;
}

int		width_accur(char *str, t_rule *p, int i)
{
	if (width_if(str, i))
	{
		p->width = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
	}
	else if (accur_if(str, i) == 1)
	{
		p->accur = ft_atoi(&str[++i]);
		while (ft_isdigit(str[i]))
			i++;
	}
	return (i);
}

int		read_rules(char *str, int i, t_rule *p)
{
	int j;

	j = 0;
	while (str[i])
	{
		if (flag_if(str, i, p) == 1)
			p->flag[j++] = str[i++];
		else if (flag_if(str, i, p) == 2)
			i++;
		else if (length_if(str, i))
			i = length(str, i, p);
		else if (width_if(str, i) || (accur_if(str, i) == 1))
			i = width_accur(str, p, i);
		else if (accur_if(str, i) == 2)
		{
			p->accur = -1;
			i++;
		}
		else
		{
			p->type = str[i++];
			break ;
		}
	}
	return (i);
}

int		ft_printf(char *str, ...)
{
	int		count;
	int		i;
	va_list	ar;
	t_rule	*p;

	va_start(ar, str);
	i = 0;
	count = 0;
	p = (t_rule*)malloc(sizeof(t_rule));
	while (str[i])
	{
		reset_rules(p);
		if (str[i] == '%')
		{
			i++;
			i = read_rules(str, i, p);
			count += check_type(p, ar);
		}
		else if (str[i] != '%' && ++count)
			ft_putchar(str[i++]);
	}
	va_end(ar);
	free(p);
	return (count);
}
