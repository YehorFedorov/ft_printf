/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:04:35 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/22 13:12:36 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		helper_string(t_rule *p, int flag, int length)
{
	int		i;

	i = 0;
	if (p->width > length)
		while (p->width-- > length)
		{
			if (flag == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			i++;
		}
	return (i);
}

int		len(t_rule *p, char *str)
{
	int		length;

	length = ft_strlen(str);
	length == 0 ? p->accur = 0 : 1;
	length = p->accur != 0 && length > p->accur ? p->accur : length;
	length = length == -1 ? 0 : length;
	return (length);
}

int		print_string(t_rule *p, char *str)
{
	int		flag;
	int		length;
	char	*tmp;

	flag = check_flag(p);
	if (str == NULL)
		str = "(null)";
	length = len(p, str);
	tmp = ft_strsub(str, 0, length);
	if (flag == 0 || flag == 1)
	{
		length += helper_string(p, flag, length);
		ft_putstr(tmp);
	}
	else
	{
		ft_putstr(tmp);
		length += helper_string(p, flag, length);
	}
	free(tmp);
	return (length);
}
