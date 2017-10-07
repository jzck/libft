/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsepjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:54:06 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/07 17:54:07 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsepjoin(char **tab, char sep)
{
	char	*join;
	char	**p;
	int		len;

	len = 0;
	if (!(p = tab))
		return (NULL);
	while (*p)
		len += ft_strlen(*p++) + 1;
	if (!(join = ft_strnew(len)))
		return (NULL);
	*join = 0;
	p = tab;
	while (*p)
	{
		ft_strcat(join, *p++);
		ft_strcat(join, &sep);
	}
	join[len - 1] = 0;
	return (join);
}
