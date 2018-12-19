/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 21:35:10 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/18 23:40:48 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			power_of_two(int x, int y)
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
	return (
		r.low2 + (value - r.low1) * (r.high2 - r.low2) / (r.high1 - r.low1));
}
