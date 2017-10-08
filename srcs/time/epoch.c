/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epoch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:58:42 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/08 13:15:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mytime.h"

uint64_t	epoch_micro(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

double		time_milli(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((double)((double)tv.tv_sec / 1000. + tv.tv_usec * 1000.));
}
