/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_basic_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/04/23 00:36:34 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vector		vector_const_add(t_vector a, float b)
{
	t_vector res;

	res.x = a.x + b;
	res.y = a.y + b;
	res.z = a.z + b;
	return (res);
}

t_vector		vector_add(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_vector		vector_subtract(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_vector		vector_multiply(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	return (res);
}

t_vector		vector_divide(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.x / b.x;
	res.y = a.y / b.y;
	res.z = a.z / b.z;
	return (res);
}
