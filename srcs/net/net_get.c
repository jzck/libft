/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   net_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:59:19 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/07 17:59:20 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		net_get(int sock, char *msg, int size)
{
	int		ack;

	ack = htons(ACK);
	if (read(sock, msg, size) < 0)
		return (-1);
	if (write(sock, (char*)&ack, sizeof(ack)) < 0)
		return (-1);
	return (0);
}

int		net_get_fd(int sock, int fd, int size)
{
	int		ack;
	char	msg[size];

	ack = htons(ACK);
	if (read(sock, msg, size) < 0)
		return (-1);
	if (write(sock, (char*)&ack, sizeof(ack)) < 0)
		return (-1);
	if (write(fd, msg, size) < 0)
		return (-1);
	return (0);
}

int		net_get_large(int sock, int fd)
{
	int		i;
	int		num_blks;
	int		num_last_blk;

	net_get(sock, (char*)&num_blks, sizeof(num_blks));
	net_get(sock, (char*)&num_last_blk, sizeof(num_last_blk));
	num_blks = ntohs(num_blks);
	num_last_blk = ntohs(num_last_blk);
	i = -1;
	while (++i < num_blks - 1)
		net_get_fd(sock, fd, NET_MAXSIZE);
	if (num_last_blk)
		net_get_fd(sock, fd, num_last_blk);
	return (0);
}
