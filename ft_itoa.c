#include "libft.h"

static size_t	ft_size(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strnew(ft_size(n) + 1);
	if (n == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (n)
	{
		str[i++] = FT_ABS(n % 10) + '0';
		n /= 10;
	}
	if (FT_NEG(n))
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
