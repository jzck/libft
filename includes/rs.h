/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:38:51 by ariard            #+#    #+#             */
/*   Updated: 2018/02/12 19:39:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_RS_H
# define LIBFT_RS_H

# include <float.h>
# include <dlfcn.h>

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
