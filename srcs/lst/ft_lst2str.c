/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:53:18 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/07 17:53:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lst2str(t_list *list)
{
	size_t		size;
	t_list		*tmp;
	char		*new;

	size = 0;
	tmp = list;
	while (tmp)
	{
		size += ft_strlen((char *)tmp->content) + 1;
		tmp = tmp->next;
	}
	new = ft_memalloc(size);
	while (list)
	{
		ft_strcat(new, (char *)list->content);
		if (list->next)
			ft_strcat(new, "  ");
		list = list->next;
	}
	return (new);
}
