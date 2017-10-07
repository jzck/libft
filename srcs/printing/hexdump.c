/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:56:14 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/07 17:56:40 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static void	print_hex_contents(void *addr, unsigned int size)
{
	void	*a;

	a = addr;
	while (a - addr < 16)
	{
		if ((a - addr) >= size)
			break ;
		else
			ft_printf("%02x", *(unsigned char*)a);
		ft_putchar(' ');
		a++;
	}
}

void		*hexdump(void *addr, unsigned int offset, unsigned int size)
{
	void	*a;

	addr += offset;
	a = addr;
	if (addr == NULL)
		return (addr);
	while ((a - addr) < size)
	{
		ft_printf("%0*llx\t", 16, (a - addr) + (unsigned long)offset);
		print_hex_contents(a, (size - (a - addr)));
		ft_putchar('\n');
		a += 16;
	}
	return (addr);
}
