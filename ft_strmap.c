/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:58:24 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/04 11:26:42 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	size_t	i;
	char	*out;

	size = ft_strlen(s);
	out = (char *)malloc(sizeof(char) * (size + 1));
	if (!out)
		return (NULL);
	i = -1;
	while (++i < size)
		out[i] = (*f)(s[i]);
	out[i] = '\0';
	return (out);
}
