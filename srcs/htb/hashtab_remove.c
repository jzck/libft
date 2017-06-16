/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:46:48 by ariard            #+#    #+#             */
/*   Updated: 2017/05/16 17:34:56 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*hashtab_remove(t_hashtab *htb, void *key,
		int (*match)(const void *data_ref, const void *key))	
{
	t_list	*data;

	if ((data = hashtab_lookup(htb, key, match)))
		return(ft_lst_removeif(&data, key, match));
	return (NULL);
}