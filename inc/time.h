/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 06:37:13 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 17:57:03 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TIME_H
# define __TIME_H

typedef struct	s_time
{
	float		curr_time;
	float		last_time;
	float		delta;
}				t_time;

#endif
