/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 10:49:12 by jhalford          #+#    #+#             */
<<<<<<< HEAD:src/str/ft_strncmp.c
/*   Updated: 2016/11/03 16:11:00 by jhalford         ###   ########.fr       */
=======
/*   Updated: 2016/11/05 11:22:29 by jhalford         ###   ########.fr       */
>>>>>>> 1f1cb4b14d273f8950585bfb2f8033e3674a5783:ft_strncmp.c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i) && i < (int)n)
		i++;
	if (i < (int)n)
		return (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i));
	else
		return (0);
}
