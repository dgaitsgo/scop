/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 12:35:08 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 00:33:49 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

double		largest(double a, double b)
{
	return (a > b ? a : b);
}

int			sgn(int x)
{
	return ((x > 0) - (x < 0));
}

double		smallest(double a, double b)
{
	return (a > b ? b : a);
}

float	in_radians(float degrees)
{
	float pi;

	pi = 3.14159;
	return (degrees * (pi / 180));
}

float euclidean_distance3d(t_vector a, t_vector b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2)));
}

int		power_of_two(int x, int y)
{
	return ((x & (x - 1)) != 0 || (y & (y - 1)) != 0);
}

t_range		new_range(float low1, float high1, float low2, float high2)
{
	t_range r;
	
	r.low1 = low1;
	r.high1 = high1;
	r.low2 = low2;
	r.high2 = high2;
	return (r);
}

float		map(float value, t_range r)
{
	return (r.low2 + (value - r.low1) * (r.high2 - r.low2) / (r.high1 - r.low1));
}
