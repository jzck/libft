/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:58:43 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/03 14:58:43 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	i = -1;
	while (++i < len)
		out[i] = s[i + start];
	out[i] = '\0';
	return (out);
}
