/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:03:58 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/03 18:04:23 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sstradd(char **sstr, char *new)
{
	int		i;
	int		size;
	char	**newlist;

	i = 0;
	size = 0;
	while (sstr && sstr[size])
		size++;
	newlist = (char **)malloc(sizeof(char *) * (size + 3));
	while (sstr && *sstr)
		newlist[i++] = *sstr++;
	newlist[i++] = new;
	newlist[i] = NULL;
	return (newlist);
}
