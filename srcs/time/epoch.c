/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epoch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:58:42 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/07 17:58:43 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mytime.h"

size_t	epoch_micro(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}
