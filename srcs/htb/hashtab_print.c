/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:38:14 by ariard            #+#    #+#             */
/*   Updated: 2018/02/08 22:19:48 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		hashtab_print(t_hashtab *htb, int (*printer)())
{
	int		bucket;

	bucket = -1;
	while (++bucket != htb->capacity)
		ft_lstiter(htb->head[bucket], printer, NULL);
}
