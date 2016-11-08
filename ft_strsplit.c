/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:58:40 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 12:56:48 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	countwords(char const *s, char c)
{
	if (c == '\0')
		return ((*s == '\0') ? 0 : 1);
	while (*s == c)
		s++;
	if (*s == '\0')
		return (0);
	while (*s != c && *s != '\0')
		s++;
	return (1 + countwords(s, c));
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		w;

	if (!s)
		return (0);
	w = countwords(s, c);
	if ((arr = (char **)malloc(sizeof(char *) * (w + 1))))
	{
		i = 0;
		while (i < w)
		{
			while (*s == c)
				++s;
			j = 0;
			while (*(s + j) != c)
				++j;
			if ((arr[i] = ft_strnew(j)))
				ft_strncpy(arr[i++], s, j);
			s += j;
		}
		arr[i] = 0;
	}
	return (arr);
}
