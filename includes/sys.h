/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:24:23 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/07 18:10:34 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYS_H
# define SYS_H

# define FT_XATTR_SIZE	10000
# define STDIN			STDIN_FILENO
# define STDOUT			STDOUT_FILENO
# define STDERR			STDERR_FILENO
# define STDBUG			9

# define PIPE_READ		0
# define PIPE_WRITE		1

# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/stat.h>
# include <fcntl.h>

int		open_new(char *filename, int oflag);

#endif
