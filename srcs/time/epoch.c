#include "mytime.h"

size_t	epoch_micro(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}
