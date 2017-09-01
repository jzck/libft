#include "net.h"

void	tcphdr_init(struct tcphdr *header)
{
	memset(header, 0, sizeof(*header));
	header->source = htons(0);
	header->dest = htons(0);
	header->seq = epoch_micro();
	header->ack_seq = 0;
	header->doff = 5;
	header->fin = 0;
	header->syn = 0;
	header->rst = 0;
	header->psh = 0;
	header->ack = 0;
	header->urg = 0;
	header->window = htons(1024);
	header->check = 0;
	header->urg_ptr = 0;
}
