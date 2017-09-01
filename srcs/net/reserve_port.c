#include "net.h"

int	reserve_port(int *port)
{
	struct sockaddr_in sa;
	int sockfd;
	unsigned short i;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		return (1);
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = INADDR_ANY;
	i = 49152;
	while (i < 65535)
	{
		sa.sin_port = htons(i);
		if (bind(sockfd, (struct sockaddr*)&sa, sizeof(sa)) == 0)
		{
			*port = i;
			return (0);
		}
		++i;
	}
	return (1);
}
