/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 22:08:40 by ariard            #+#    #+#             */
/*   Updated: 2018/02/08 22:19:49 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

void		hashtab_clean(t_hashtab *htb, int (*destroy)())
{
	int		bucket;

	bucket = -1;
	while (++bucket < htb->capacity)
		ft_lstiter(htb->head[bucket], destroy, NULL);
}
