/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:24:33 by ariard            #+#    #+#             */
/*   Updated: 2018/02/12 19:25:31 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

struct s_stats g_rs = {0, 0, 0, 0, 0, 0, 0};

void	rs_clear(void)
{
	g_rs.count = 0;
	g_rs.min = DBL_MAX;
	g_rs.max = -DBL_MAX;
}

void	rs_push(double n)
{
	double	delta;

	g_rs.count++;
	n < g_rs.min ? g_rs.min = n : (0);
	n > g_rs.max ? g_rs.max = n : (0);
	if (g_rs.count == 1)
	{
		g_rs.avg = n;
		g_rs.m = 0;
	}
	else
	{
		delta = n - g_rs.avg;
		g_rs.avg += delta / g_rs.count;
		g_rs.m += delta * (n - g_rs.avg);
	}
}

void	rs_calcmore(void)
{
	void	*libm;
	double	(*sqrt)(double);

	if (g_rs.count == 0)
	{
		g_rs.min = 0;
		g_rs.max = 0;
	}
	if (g_rs.count < 2)
	{
		g_rs.var = 0;
		g_rs.stdev = 0;
		return ;
	}
	g_rs.var = g_rs.m / (g_rs.count - 1);
	if ((libm = dlopen("libm.dylib", 0)) == NULL)
		printf("%s\n", dlerror());
	else if ((sqrt = dlsym(libm, "sqrt")) == NULL)
		printf("%s\n", dlerror());
	else
		g_rs.stdev = sqrt(g_rs.var);
}
