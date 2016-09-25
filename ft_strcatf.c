#include "libft.h"

char	*ft_strcatf(char *s1, const char *s2)
{
	char	buf[ft_strlen(s2)];

	ft_strcpy(buf, s1);
	ft_strcpy(s1, s2);
	ft_strcat(s1, buf);
	return (s1);
}
