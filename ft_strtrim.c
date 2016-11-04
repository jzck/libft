/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:58:45 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/04 10:36:54 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ltrim(char *s)
{
	while (FT_SEP(*s))
		s++;
	return ((char *)s);
}

static char	*ft_rtrim(char *s)
{
	char	*back;

	back = s + ft_strlen(s) - 1;
	while (FT_SEP(*back))
		back--;
	*(back + 1) = '\0';
	return (s);
}

char		*ft_strtrim(char const *s)
{
	char	*trim;
	char	*mem;

	if (!s)
		return (NULL);
	trim = ft_strdup(s);
	mem = trim;
	if (!trim)
		return (NULL);
	trim = ft_rtrim(ft_ltrim(trim));
	trim = ft_strdup(trim);
	free(mem);
	return (trim);
}
