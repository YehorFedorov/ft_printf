/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:17:51 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/21 19:00:10 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flag_minus(t_rule *p)
{
	if (p->flag[0] == '-' || p->flag[1] == '-' || p->flag[2] == '-' ||
		p->flag[3] == '-' || p->flag[4] == '-')
		return (1);
	return (0);
}

int		flag_plus(t_rule *p)
{
	if (p->flag[0] == '+' || p->flag[1] == '+' || p->flag[2] == '+' ||
		p->flag[3] == '+' || p->flag[4] == '+')
		return (1);
	return (0);
}

int		flag_zero(t_rule *p)
{
	if (p->flag[0] == '0' || p->flag[1] == '0' || p->flag[2] == '0' ||
		p->flag[3] == '0' || p->flag[4] == '0')
		return (1);
	return (0);
}

int		flag_space(t_rule *p)
{
	if (p->flag[0] == ' ' || p->flag[1] == ' ' || p->flag[2] == ' ' ||
		p->flag[3] == ' ' || p->flag[4] == ' ')
		return (1);
	return (0);
}

int		flag_hash(t_rule *p)
{
	if (p->flag[0] == '#' || p->flag[1] == '#' || p->flag[2] == '#' ||
		p->flag[3] == '#' || p->flag[4] == '#')
		return (1);
	return (0);
}
