/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   net.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:38:40 by ariard            #+#    #+#             */
/*   Updated: 2018/02/12 19:38:41 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NET_H
# define NET_H

# define ACK		2
# define NACK		3

# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>

int		create_server(int port, int backlog, char *protoname);
int		create_client(char *addr, int port, char *protoname);

int		net_send(int sock, char *msg, int size);
int		net_get(int sock, char *msg, int size);
int		net_get_fd(int sock, int fd, int size);

#endif
