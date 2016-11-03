/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:57:24 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/03 14:57:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!content)
	{
		new = malloc(sizeof(*new));
		if (!new)
			return (NULL);
		new->content_size = 0;
		new->content = NULL;
	}
	else
	{
		new = (t_list *)malloc(sizeof(*new));
		if (!new)
			return (NULL);
		new->content_size = content_size;
		new->content = ft_memalloc(content_size + 1);
		ft_memcpy(new->content, content, content_size);
	}
	new->next = NULL;
	return (new);
}
