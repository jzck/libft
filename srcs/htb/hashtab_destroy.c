/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 21:35:07 by ariard            #+#    #+#             */
/*   Updated: 2018/02/08 22:19:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

void		hashtab_destroy(t_hashtab *htb, void (*destroy)())
{
	int		bucket;

	bucket = -1;
	while (++bucket < htb->capacity)
		ft_lstdel(&htb->head[bucket], destroy);
}
