#include "net.h"

void iphdr_init(struct iphdr *header)
{
	memset(header, 0, sizeof(*header));
	header->version = 4;
	header->ihl = 5;
	header->tos = 0;
	header->tot_len = 0;
	header->id = ntohl(epoch_micro());
	header->frag_off = 0;
	header->ttl = 255;
	header->protocol = 0;
	header->daddr = 0;
	header->saddr = 0;
	header->check = 0;
}
