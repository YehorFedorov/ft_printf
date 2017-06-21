/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:35:01 by efedorov          #+#    #+#             */
/*   Updated: 2016/12/01 12:11:35 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *alst;
	tmp2 = NULL;
	while (tmp1 != NULL)
	{
		del(tmp1->content, tmp1->content_size);
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	*alst = NULL;
}
