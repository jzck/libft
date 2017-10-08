/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mytime.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:43:12 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/08 13:16:26 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYTIME_H
# define MYTIME_H

# include <sys/time.h>

# include "libft.h"

uint64_t	epoch_micro(void);
double		time_milli(void);

#endif
