/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:56:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/07 17:57:28 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** If file already exists, create xxx(1) instead, etc up to 9
*/

int		open_new(char *filename, int oflag)
{
	char	*fname;
	int		fd;
	int		i;
	int		len;

	len = ft_strlen(filename);
	fname = ft_strnew(len + 4);
	ft_strcpy(fname, filename);
	i = 0;
	while (i < 10 && (fd = open(fname, oflag | O_CREAT | O_EXCL, 0644)) < 0
			&& errno == EEXIST)
	{
		fname[len] = '(';
		fname[len + 1] = ++i + '0';
		fname[len + 2] = ')';
	}
	ft_strdel(&fname);
	return (fd);
}
