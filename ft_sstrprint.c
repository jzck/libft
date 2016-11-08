/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:04:15 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/08 16:36:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sstrprint(char **list, char sep)
{
	int		i;

	i = 0;
	while (list[i])
	{
		ft_putstr(list[i++]);
		ft_putchar(sep);
	}
}
