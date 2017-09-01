#ifndef NET_H
# define NET_H

# define ACK			2
# define NACK			3
# define NET_MAXSIZE 	512

# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <netinet/tcp.h>
# include <arpa/inet.h>

#include "mytime.h"

int		create_server(int port, int backlog, char *protoname);
int		create_client(char *addr, int port, char *protoname);
void	listener(int domain, int sock, int proto, void (*handler)(void *buf, int bytes, struct sockaddr_in *addr));

int		net_send(int sock, char *msg, int size);
int		net_send_large(int sock, char *msg, int size);
int		net_get(int sock, char *msg, int size);
int		net_get_fd(int sock, int fd, int size);
int		net_get_large(int sock, int fd);

int		reserve_port(int *port);

void	tcphdr_init(struct tcphdr *header);
void	iphdr_init(struct iphdr *header);


#endif
