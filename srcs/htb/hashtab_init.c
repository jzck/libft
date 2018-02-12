/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:13:06 by ariard            #+#    #+#             */
/*   Updated: 2018/02/12 19:20:38 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

void		hashtab_init(t_hashtab *htb,
			int capacity, int (*hashfunc) (const void *key, int capacity))
{
	htb->head = (t_list **)ft_memalloc(capacity * sizeof(*htb->head));
	htb->capacity = capacity;
	htb->size = 0;
	htb->hashfunc = hashfunc;
}
