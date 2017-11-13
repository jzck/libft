/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:57:54 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/07 18:19:47 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double	sqrt(double x);

void	rs_init(t_rs *rs)
{
	bzero(rs, sizeof(t_rs));
	rs->count = 0;
	rs->min = DBL_MAX;
	rs->max = -DBL_MAX;
}

void	rs_push(t_rs *rs, double n)
{
	double	delta;

	rs->count++;
	n < rs->min ? rs->min = n : (0);
	n > rs->max ? rs->max = n : (0);
	if (rs->count == 1)
	{
		rs->avg = n;
		rs->m = 0;
	}
	else
	{
		delta = n - rs->avg;
		rs->avg += delta / rs->count;
		rs->m += delta * (n - rs->avg);
	}
}

void	rs_final(t_rs *rs)
{
	if (rs->count == 0)
	{
		rs->min = 0;
		rs->max = 0;
	}
	if (rs->count < 2)
	{
		rs->var = 0;
		rs->stdev = 0;
		return ;
	}
	rs->var = rs->m / (rs->count - 1);
	rs->stdev = sqrt(rs->var);
}
