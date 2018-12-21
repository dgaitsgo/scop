/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/12/20 21:44:41 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		set_vector(t_vector *res, float x, float y, float z)
{
	res->x = x;
	res->y = y;
	res->z = z;
}

void		copy_vector(t_vector *dst, t_vector *src)
{
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
}

t_vector	new_vector(float x, float y, float z)
{
	t_vector n;

	n.x = x;
	n.y = y;
	n.z = z;
	n.w = 0;
	return (n);
}

t_vector	new_point(float x, float y, float z, float w)
{
	t_vector n;

	w = 0;
	n.x = x;
	n.y = y;
	n.z = z;
	n.w = 1;
	return (n);
}

t_vector	*new_vector_ptr(float x, float y, float z)
{
	t_vector	*res;

	res = malloc(sizeof(t_vector));
	res->x = x;
	res->y = y;
	res->z = z;
	return (res);
}
