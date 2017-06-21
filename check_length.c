/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:12:00 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/21 19:05:44 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		check_len(char l, va_list ar, t_rule *p)
{
	if (p->type == 'D')
		return (print_int(p, va_arg(ar, long int)));
	else if (l == 'L')
		return (print_int(p, va_arg(ar, long long int)));
	else if (l == 'H')
		return (print_int(p, (signed char)va_arg(ar, int)));
	else if (l == 'l')
		return (print_int(p, va_arg(ar, long int)));
	else if (l == 'h')
		return (print_int(p, (short int)va_arg(ar, int)));
	else if (l == 'j')
		return (print_int(p, va_arg(ar, intmax_t)));
	else if (l == 'z')
		return (print_int(p, (size_t)va_arg(ar, size_t)));
	else
		return (print_int(p, va_arg(ar, int)));
}

int		check_len_x(char l, va_list ar, t_rule *p)
{
	if (l == 'L')
		return (print_x(p, va_arg(ar, unsigned long long int)));
	else if (l == 'H')
		return (print_x(p, (unsigned char)va_arg(ar, unsigned int)));
	else if (l == 'l')
		return (print_x(p, va_arg(ar, unsigned long int)));
	else if (l == 'h')
		return (print_x(p, (unsigned short int)va_arg(ar, unsigned int)));
	else if (l == 'j')
		return (print_x(p, va_arg(ar, uintmax_t)));
	else if (l == 'z')
		return (print_x(p, va_arg(ar, size_t)));
	else
		return (print_x(p, va_arg(ar, unsigned int)));
}

int		check_len_o(char l, va_list ar, t_rule *p)
{
	if (p->type == 'O')
		return (print_o(p, va_arg(ar, unsigned long int)));
	if (l == 'L')
		return (print_o(p, va_arg(ar, unsigned long long int)));
	else if (l == 'H')
		return (print_o(p, (unsigned char)va_arg(ar, unsigned int)));
	else if (l == 'l')
		return (print_o(p, va_arg(ar, unsigned long int)));
	else if (l == 'h')
		return (print_o(p, (unsigned short int)va_arg(ar, unsigned int)));
	else if (l == 'j')
		return (print_o(p, va_arg(ar, uintmax_t)));
	else if (l == 'z')
		return (print_o(p, va_arg(ar, size_t)));
	else
		return (print_o(p, va_arg(ar, unsigned int)));
}

int		check_len_u(char l, va_list ar, t_rule *p)
{
	if (p->type == 'U')
		return (check_len_uu(l, ar, p));
	else if (l == 'L')
		return (print_u(p, va_arg(ar, unsigned long long int)));
	else if (l == 'H')
		return (print_u(p, (unsigned char)va_arg(ar, unsigned int)));
	else if (l == 'l')
		return (print_u(p, va_arg(ar, unsigned long int)));
	else if (l == 'h')
		return (print_u(p, (unsigned short int)va_arg(ar, unsigned int)));
	else if (l == 'j')
		return (print_u(p, va_arg(ar, uintmax_t)));
	else if (l == 'z')
		return (print_u(p, va_arg(ar, size_t)));
	else
		return (print_u(p, va_arg(ar, unsigned int)));
}

int		check_len_uu(char l, va_list ar, t_rule *p)
{
	if (l == 'L')
		return (print_u(p, va_arg(ar, unsigned long long int)));
	else if (l == 'H')
		return (print_u(p, va_arg(ar, unsigned long int)));
	else if (l == 'l')
		return (print_u(p, va_arg(ar, unsigned long int)));
	else if (l == 'h')
		return (print_u(p, (unsigned long int)va_arg(ar, unsigned long int)));
	else if (l == 'j')
		return (print_u(p, va_arg(ar, uintmax_t)));
	else if (l == 'z')
		return (print_u(p, va_arg(ar, size_t)));
	else
		return (print_u(p, va_arg(ar, unsigned long int)));
}
