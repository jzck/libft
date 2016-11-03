/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:58:45 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/03 19:45:38 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*out;
	int		size;

	if (!s)
		return (NULL);
	out = ft_strdup(s);
	while (*out && FT_SEP(*out))
		out++;
	if (!out)
		return (NULL);
	size = ft_strlen(out) - 1;
	while (size >= 0 && FT_SEP(out[size]))
	{
		out[size] = '\0';
		size--;
	}
	return (out);
}
