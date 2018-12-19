/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 12:35:08 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/18 23:46:23 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

double		smallest(double a, double b)
{
	return (a > b ? b : a);
}

double		largest(double a, double b)
{
	return (a > b ? a : b);
}

int			sgn(int x)
{
	return ((x > 0) - (x < 0));
}

float		in_radians(float degrees)
{
	float pi;

	pi = 3.14159;
	return (degrees * (pi / 180));
}

float		euclidean_distance3d(t_vector a, t_vector b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2)));
}
