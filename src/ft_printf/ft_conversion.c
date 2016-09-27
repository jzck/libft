#include "ftprintf.h"

char	*ft_signed_conversion(t_fmt *fmt, va_list ap)
{
	char		base10[] = "0123456789";
	long long	arg = va_arg(ap, int);

	(void)fmt;
	return (ft_lltoa_base(arg, base10, fmt->flags));
}

char	*ft_unsigned_conversion(t_fmt *fmt, va_list ap)
{
	unsigned int		uiarg;
	unsigned long long	ullarg;
	int					i;

	i = 0;
	while (fmt->conversion != g_convs[i].id)
		i++;
	if (!*fmt->modifier
		|| ft_strcmp(fmt->modifier, "hh") == 0
		|| ft_strcmp(fmt->modifier, "h") == 0
		|| ft_strcmp(fmt->modifier, "z") == 0)
	{
		uiarg = va_arg(ap, int);
		return (ft_uitoa_base(uiarg, g_convs[i].base));
	}
	ullarg = va_arg(ap, long long);
	return (ft_ulltoa_base(ullarg, g_convs[i].base));
}

char	*ft_char_conversion(t_fmt *fmt, va_list ap)
{
	char	*ret;

	(void)fmt;
	ret = (char *)malloc(sizeof(char) + 1);
	/* if (ft_strcmp(fmt->modifier, "l") == 0) */
	/* 	va_arg(ap, wint_t); */
	ret[0] = (char)va_arg(ap, int);
	ret[1] = '\0';
	return (ret);
}

char	*ft_str_conversion(t_fmt *fmt, va_list ap)
{
	char	*ret;

	(void)fmt;
	/* if (ft_strcmp(fmt->modifier, "l") == 0) */
	/* 	va_arg(ap, wchar_t *); */
	ret = ft_strdup(va_arg(ap, char *));
	if (fmt->precision && fmt->precision < (int)ft_strlen(ret))
		ret[fmt->precision] = '\0';
	return (ret);
}