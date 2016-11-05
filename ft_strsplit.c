/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:58:40 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/05 11:17:14 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**alloc_table(char **table, const char *str, char c)
{
	int		i;
	int		n_words;

	i = 0;
	n_words = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == c)
		{
			n_words++;
			while (str[i] == c)
				i++;
		}
	}
	if (str[i - 1] != c)
		n_words++;
	if (!(table = (char**)malloc(sizeof(*table) * (n_words + 10))))
		return (NULL);
	table[n_words] = 0;
	return (table);
}

static char	**alloc_words(char **table, const char *str, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == c || !str[i])
		{
			if (!(table[j] = (char*)malloc(sizeof(**table) * (k + 10))))
				return (NULL);
			j++;
			k = 0;
			while (str[i] == c)
				i++;
		}
		k++;
	}
	return (table);
}

static char	**fill_table(char **table, const char *str, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		table[j][k] = str[i];
		i++;
		k++;
		if (str[i] == c || !str[i])
		{
			table[j][k] = '\0';
			j++;
			k = 0;
			while (str[i] == c)
				i++;
		}
	}
	return (table);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**table;

	if (!s)
		return (NULL);
	table = 0;
	if (!(table = alloc_table(table, s, c)))
		return (NULL);
	if (!(table = alloc_words(table, s, c)))
		return (NULL);
	table = fill_table(table, s, c);
	return (table);
}
