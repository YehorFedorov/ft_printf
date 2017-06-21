/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:48:13 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/21 19:30:27 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_rule
{
	int		width;
	int		accur;
	char	flag[5];
	char	type;
	char	l;
}				t_rule;

int				check_len(char l, va_list ar, t_rule *p);
int				check_len_u(char l, va_list ar, t_rule *p);
int				check_len_x(char l, va_list ar, t_rule *p);
int				check_len_o(char l, va_list ar, t_rule *p);
int				print_symb(t_rule *p, char symb, int flag);
int				minus_int(t_rule *p, int i, char *str, int flag);
int				flag_minus(t_rule *p);
int				flag_plus(t_rule *p);
int				flag_zero(t_rule *p);
int				flag_space(t_rule *p);
int				flag_hash(t_rule *p);
int				check_flag(t_rule *p);
int				print_string(t_rule *p, char *str);
int				ft_printf(char *str, ...);
int				flag_if(char *str, int i, t_rule *p);
int				width_if(char *str, int i);
int				accur_if(char *str, int i);
int				length_if(char *str, int i);
int				length(char *str, int i, t_rule *p);
int				check_type(t_rule *p, va_list ar);
int				print_int(t_rule *p, intmax_t numb);
int				print_x(t_rule *p, uintmax_t numb);
int				print_p(t_rule *p, void *s);
int				print_o(t_rule *p, uintmax_t numb);
char			*ft_itoa_base(intmax_t value, int base);
char			*ft_itoa_base_hex(uintmax_t value, int base);
int				print_u(t_rule *p, uintmax_t numb);
int				check_len_uu(char l, va_list ar, t_rule *p);

#endif
