/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mytime.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:43:12 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/25 18:33:09 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYTIME_H
# define MYTIME_H
# include "libft.h"

typedef struct s_mytime		t_mytime;

struct	s_mytime
{
	char	*year;
	char	*month;
	char	*day;
	char	*hour;
	char	*min;
	char	*sec;
};


int			ft_time_isrecent(time_t event);

t_mytime	*ft_mytime_get(time_t epoch);
void		ft_mytime_free(t_mytime **time);

#endif