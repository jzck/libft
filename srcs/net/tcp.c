/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forge_tcp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 18:02:34 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/08 15:54:16 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "net.h"

void	tcp_hdrinit(struct tcphdr *header)
{
	memset(header, 0, sizeof(*header));
	header->th_sport = htons(0);
	header->th_dport = htons(0);
	header->th_seq = epoch_micro();
	header->th_ack = 0;
	header->th_off = 5;
	header->th_flags = 0;
	header->th_win = htons(1024);
	header->th_sum = 0;
	header->th_urp = 0;
}
