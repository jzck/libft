/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   net.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 18:06:12 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/08 16:52:48 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NET_H
# define NET_H

# define ACK			2
# define NACK			3
# define NET_MAXSIZE 	512

# include <sys/socket.h>
# include <netdb.h>
# include <net/if.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <netinet/tcp.h>
# include <netinet/ip_icmp.h>
# include <arpa/inet.h>

# include "mytime.h"

/*
**	utilities
*/

int				reserve_port(int *port);
unsigned short	cksum(void *b, int len);
int				host_format(struct sockaddr *addr);

/*
**		lazy setup
*/
int				create_server(int port, int backlog, char *protoname);
int				create_client(char *addr, int port, char *protoname);
void			listener(int domain, int sock, int proto,
			void (*handler)(void *buf, int bytes, struct sockaddr_in *addr));

/*
**		lazy framing
*/
int				net_send(int sock, char *msg, int size);
int				net_send_large(int sock, char *msg, int size);
int				net_get(int sock, char *msg, int size);
int				net_get_fd(int sock, int fd, int size);
int				net_get_large(int sock, int fd);

/*
**		ip
*/
void			ip_hdrinit(struct ip *hdr);
void			ip_load_icmp(struct icmp *icmp, void *buf);

/*
**		tcp
*/
void			tcp_hdrinit(struct tcphdr *header);

#endif
