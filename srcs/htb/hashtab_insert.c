/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:30:39 by ariard            #+#    #+#             */
/*   Updated: 2018/02/12 19:20:23 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

int		hashtab_insert(t_hashtab *htb, t_list *new,
		void *key, int (*match)(const void *data_ref, const void *key))
{
	int	bucket;

	if (hashtab_lookup(htb, key, match))
		return (-1);
	bucket = htb->hashfunc(key, htb->capacity);
	ft_lsteadd(&htb->head[bucket], new);
	htb->size++;
	return (bucket);
}
