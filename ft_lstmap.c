/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:41:00 by efedorov          #+#    #+#             */
/*   Updated: 2016/12/01 11:59:15 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*ft_back(t_list *lst, t_list *new)
{
	t_list	*tmp;

	if (lst != NULL)
	{
		tmp = lst;
		while (lst->next)
			lst = lst->next;
		lst->next = new;
		lst = tmp;
	}
	else
		lst = new;
	return (lst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_tmp;
	t_list	*new_lst;
	t_list	*s1;
	t_list	*s2;
	t_list	*src;

	s1 = lst;
	new_lst = NULL;
	while (s1)
	{
		src = s1->next;
		s2 = f((t_list*)s1);
		new_tmp = ft_lstnew(s2->content, s2->content_size);
		new_lst = ft_back(new_lst, new_tmp);
		s1 = src;
	}
	return (new_lst);
}
