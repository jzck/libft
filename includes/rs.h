/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 18:05:30 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/08 15:59:58 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_RS_H
# define LIBFT_RS_H

# include <float.h>
# include <dlfcn.h>
# include <math.h>

extern struct	s_stats {
	int		count;
	double	min;
	double	max;
	double	avg;
	double	m;
	double	stdev;
	double	var;
} g_rs;

void			rs_clear();
void			rs_push(double n);
void			rs_calcmore();

#endif
