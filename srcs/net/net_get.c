/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   net_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:23:20 by ariard            #+#    #+#             */
/*   Updated: 2018/02/12 19:23:21 by ariard           ###   ########.fr       */
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
