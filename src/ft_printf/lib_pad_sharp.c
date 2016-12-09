/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_pad_sharp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:33:48 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/09 19:07:55 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pad_sharp_o(char *str, t_fmt *fmt)
{
	char	buf[100];

	(void)fmt;
	ft_bzero(buf, 100);
	if (str[0] != '0')
		ft_strcatf(buf, "0");
}

void	ft_pad_sharp_xb(char *str, t_fmt *fmt)
{
	char	start[3] = {'0',fmt->conversion, 0};
	int		i;

	i = 0;
	if (str[0] == '0')
	{
		if (str[1] == '0')
			str[1] = fmt->conversion;
		else
		{
			str[0] = fmt->conversion;
			ft_strcatf(str, "0");
		}
	}
	else
		ft_strcatf(str, start);
}
