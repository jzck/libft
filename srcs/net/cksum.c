/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cksum.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 12:45:43 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/08 12:48:41 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "net.h"

unsigned short	cksum(void *b, int len)
{
	unsigned short	*buf;
	unsigned int	sum;

	buf = b;
	sum = 0;
	while (len > 1)
	{
		sum += *((unsigned short*)buf++);
		len -= 2;
	}
	if (len == 1)
		sum += *(unsigned char*)buf;
	sum = (sum >> 16) + (sum & 0xFFFF);
	return (~(sum + (sum >> 16)));
}
