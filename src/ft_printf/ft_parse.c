#include "ftprintf.h"

t_fmt	*ft_parse(char **format, va_list ap)
{
	t_fmt		*fmt;

	fmt = ft_fmt_init();
	ft_parse_flags(fmt, format);
	ft_parse_width(fmt, format, ap);
	ft_parse_precision(fmt, format, ap);
	ft_parse_modifiers(fmt, format);
	fmt->conversion = **format;
	(*format)++;
	ft_fmt_validate_mod(fmt);
	ft_fmt_validate_flags(fmt);
	ft_fmt_simplify(fmt);
	fmt->valid = ft_fmt_validate_conversion(fmt) ? 0 : 1;

	/* ft_fmt_print(fmt); */
	return (fmt);
}

void	ft_parse_flags(t_fmt *fmt, char **format)
{
	int		i;
	char	*str;


	i = 0;
	str = *format;
	while (str[i])
	{
		if (ft_strchr(ALL_FLAGS, (int)str[i]))
		{
			if (!ft_strchr(fmt->flags, (int)str[i]))
				ft_strncat(fmt->flags, str + i, 1);
		}
		else
			break ;
		i++;
	}
	*format += i;
	/* printf("\nparse_flags: %s\n", *format); */
	/* fflush(stdout); */
}

void	ft_parse_width(t_fmt *fmt, char **format, va_list ap)
{
	int		i;
	char	buf[10];
	char	*str;

	i = 0;
	str = *format;
	if (str[i] == '*')
	{
		i++;
		fmt->width = va_arg(ap, int);
	}
	else
	{
		ft_strcpy(buf, "0");
		while (ft_isdigit((int)(str[i])))
			ft_strncat(buf, str + i++, 1);
		fmt->width = ft_atoi(buf);
	}
	*format += i;
	/* printf("found width: %i\n", fmt->width); */
	/* printf("\nparse_nums: %s\n", *format); */
	/* fflush(stdout); */
}

void	ft_parse_precision(t_fmt *fmt, char **format, va_list ap)
{
	int		i;
	char	buf[10];
	char	*str;

	i = 0;
	str = *format;
	if (str[i] == '.')
	{
		if (str[++i] == '*')
		{
			i++;
			fmt->precision = va_arg(ap, int);
		}
		else
		{
			ft_strcpy(buf, "0");
			while (ft_isdigit(str[i]))
				ft_strncat(buf, str + i++, 1);
			fmt->precision = ft_atoi(buf);
		}
	}
	/* printf("found preci: %i\n", fmt->precision); */
	*format += i;
}


void	ft_parse_modifiers(t_fmt *fmt, char **format)
{
	char	*str;

	str = *format;
	if (str[0] == 'h' && str[1] == 'h')
		ft_strcpy(fmt->modifier, "hh");
	else if (str[0] == 'h' && str[1] != 'h')
		ft_strcpy(fmt->modifier, "h");
	else if (str[0] == 'l' && str[1] == 'l')
		ft_strcpy(fmt->modifier, "ll");
	else if (str[0] == 'l' && str[1] != 'l')
		ft_strcpy(fmt->modifier, "l");
	else if (str[0] == 'j')
		ft_strcpy(fmt->modifier, "j");
	else if (str[0] == 'z')
		ft_strcpy(fmt->modifier, "z");
	else
		ft_strcpy(fmt->modifier, "");
	*format += ft_strlen(fmt->modifier);
	/* printf("\nparse_mods: %s\n", *format); */
	/* fflush(stdout); */
}