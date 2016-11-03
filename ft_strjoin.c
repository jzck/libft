/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:58:18 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/03 14:58:18 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	join = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcpy(join, s1);
	ft_strcat(join, s2);
	return (join);
}
