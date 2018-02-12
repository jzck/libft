/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   net_get_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:22:37 by ariard            #+#    #+#             */
/*   Updated: 2018/02/12 19:25:32 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
