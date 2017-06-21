/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:59:51 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/21 17:02:26 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flag_if(char *str, int i, t_rule *p)
{
	if (str[i] == '#' || str[i] == '0' || str[i] == '-' || str[i] == '+' ||
		str[i] == ' ')
	{
		if (str[i] != p->flag[0] && str[i] != p->flag[1] &&
			str[i] != p->flag[2] && str[i] != p->flag[3] &&
			str[i] != p->flag[4])
			return (1);
		else
			return (2);
	}
	return (0);
}

int		width_if(char *str, int i)
{
	if (str[i] >= '1' && str[i] <= '9')
		return (1);
	return (0);
}

int		accur_if(char *str, int i)
{
	if (str[i] == '.' && (str[i + 1] >= '1' && str[i + 1] <= '9'))
		return (1);
	else if (str[i] == '.' &&
			(str[i + 1] == '0' || !(str[i + 1] >= '1' && str[i + 1] <= '9')))
		return (2);
	return (0);
}

int		length_if(char *str, int i)
{
	if (str[i] == 'l' || str[i] == 'h' || str[i] == 'j' || str[i] == 'z')
		return (1);
	return (0);
}

int		length(char *str, int i, t_rule *p)
{
	if ((str[i] == 'l' && str[i + 1] == 'l') &&
		(p->l == '\0' || p->l == 'H' || p->l == 'h' || p->l == 'l'))
	{
		p->l = 'L';
		i++;
	}
	else if ((str[i] == 'h' && str[i + 1] == 'h') && p->l == '\0')
	{
		p->l = 'H';
		i++;
	}
	else if (str[i] == 'l' && (p->l == '\0' || p->l == 'H' || p->l == 'h'))
		p->l = 'l';
	else if (str[i] == 'h' && (p->l == '\0' || p->l == 'H'))
		p->l = 'h';
	else if (str[i] == 'j')
		p->l = 'j';
	else if (str[i] == 'z' &&
			(p->l == '\0' || p->l == 'H' ||
			p->l == 'h' || p->l == 'l' || p->l == 'L'))
		p->l = 'z';
	i++;
	return (i);
}
