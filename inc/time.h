/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 06:37:13 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 07:09:23 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TIME_H
# define __TIME_H

typedef struct s_time
{
	float		curr_time;
	float		last_time;
	float		delta;
}				t_time;

#endif
