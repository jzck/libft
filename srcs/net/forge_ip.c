/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forge_ip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 18:02:39 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/07 18:18:07 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "net.h"

void	iphdr_init(struct ip *header)
{
	memset(header, 0, sizeof(*header));
	header->ip_v = 4;
	header->ip_hl = 5;
	header->ip_tos = 0;
	header->ip_len = 0;
	header->ip_id = ntohl(epoch_micro());
	header->ip_off = 0;
	header->ip_ttl = 255;
	header->ip_p = 0;
	header->ip_sum = 0;
	memset(&header->ip_src, 0, sizeof(struct in_addr));
	memset(&header->ip_dst, 0, sizeof(struct in_addr));
}
