/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   net_send.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:23:11 by ariard            #+#    #+#             */
/*   Updated: 2018/02/12 19:23:33 by ariard           ###   ########.fr       */
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
