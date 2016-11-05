/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:57:21 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/03 16:40:39 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lsteadd(t_list **alst, t_list *new)
{
	t_list	*lst;

	lst = *alst;
	new->next = NULL;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	else
		*alst = new;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*out;
	t_list	*elem;

	out = NULL;
	while (lst)
	{
		elem = (*f)(lst);
		elem = ft_lstnew(elem->content, elem->content_size);
		ft_lsteadd(&out, elem);
		lst = lst->next;
	}
	return (out);
}
