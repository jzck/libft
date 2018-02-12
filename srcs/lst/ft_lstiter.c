/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:57:19 by jhalford          #+#    #+#             */
/*   Updated: 2018/02/12 19:20:43 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstiter(t_list *lst, int (*f)(), void *data)
{
	if (!lst)
		return (0);
	if ((*f)(lst->content, data))
		return (1);
	return (ft_lstiter(lst->next, f, data));
}
