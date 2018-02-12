/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_lookup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:38:41 by ariard            #+#    #+#             */
/*   Updated: 2018/02/12 19:21:12 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*hashtab_lookup(t_hashtab *htb, void *key,
		int (*match)(const void *data_ref, const void *key))
{
	int		bucket;

	if ((bucket = htb->hashfunc(key, htb->capacity)))
		return (ft_lst_find(htb->head[bucket], key, match));
	return (NULL);
}
