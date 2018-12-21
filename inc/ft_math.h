/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 12:36:53 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 12:12:50 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_MATH_H
# define __FT_MATH_H

typedef struct	s_range
{
	float		low1;
	float		high1;
	float		low2;
	float		high2;
}				t_range;

float			in_radians(float degrees);
float			calc_fov(float theta);
double			largest(double a, double b);
int				sgn(int x);
double			smallest(double a, double b);
float			euclidean_distance3d(t_vector a, t_vector b);
t_range			new_range(float low1, float high1, float low2, float high2);
float			map(float value, t_range r);
#endif
