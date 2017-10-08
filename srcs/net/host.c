/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 15:47:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/08 15:58:30 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "net.h"

int		host_format(struct sockaddr *addr)
{
	char	dn[1024];
	char	sv[20];
	char	ip[INET_ADDRSTRLEN];

	if (getnameinfo(addr, sizeof(*addr), dn, sizeof(dn),
				sv, sizeof(sv), 0))
	{
		perror("getnameinfo");
		return (1);
	}
	printf(" %s (%s)", dn,
			inet_ntop(AF_INET, &(((struct sockaddr_in*)addr)->sin_addr),
				ip, INET_ADDRSTRLEN));
	return (0);
}
