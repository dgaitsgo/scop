/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 10:13:30 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 17:53:48 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 42

typedef struct		s_gnl
{
	int				fd;
	char			*buff;
	char			*bsn;
	struct s_gnl	*right;
	struct s_gnl	*left;
}					t_gnl;

int					get_next_line(int const fd, char **line);

#endif
