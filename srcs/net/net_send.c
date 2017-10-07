/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   net_send.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 18:03:19 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/07 18:03:31 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		net_send(int sock, char *msg, int size)
{
	int		ack;

	if (write(sock, msg, size) < 0)
		return (-1);
	if (read(sock, (char*)&ack, sizeof(ack)) < 0)
		return (-1);
	if (ntohs(ack) != ACK)
		return (1);
	return (0);
}

int		net_send_large(int sock, char *msg, int size)
{
	int		i;
	int		num_blks;
	int		num_last_blk;

	num_blks = htons(size / NET_MAXSIZE + 1);
	num_last_blk = htons(size % NET_MAXSIZE);
	if (net_send(sock, (char*)&num_blks, sizeof(num_blks)))
		return (1);
	if (net_send(sock, (char*)&num_last_blk, sizeof(num_blks)))
		return (1);
	num_blks = ntohs(num_blks);
	num_last_blk = ntohs(num_last_blk);
	i = -1;
	while (++i < num_blks - 1)
		net_send(sock, msg + i * NET_MAXSIZE, NET_MAXSIZE);
	if (num_last_blk)
		net_send(sock, msg + i * NET_MAXSIZE, num_last_blk);
	return (0);
}
